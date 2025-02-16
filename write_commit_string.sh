# This script writes a #define macro with the current commit hash to `source/commit_string.h`.
# The macro is used to show the randomizer version in the menu.

commit_string=$(git show --no-patch --format=format:"%h")

# If there are uncommitted changes, add a marker to the string.
if ([[ -n $(git status --porcelain) ]])
then
    commit_string="${commit_string}*"
fi

# If the commit string doesn't change, don't rewrite the file to avoid useless rebuilds.
new_content="#define COMMIT_STRING \"$commit_string\""
old_content="$(cat source/commit_string.h 2> /dev/null)"
if ([[ "$new_content" != "$old_content" ]])
then
    echo $new_content > source/commit_string.h
fi
