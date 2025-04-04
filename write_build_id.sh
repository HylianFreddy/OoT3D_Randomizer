#!/bin/bash

# This script creates the name for the release git tag and the build id to show in the randomizer menu.
# It writes a #define macro with the build id to `source/build_id.h`.

if [[ -n $GITHUB_ENV ]]
then
    # Building from GitHub Actions
    GITHUB_BUILD_TYPE=$1
    GITHUB_INPUT_VERSION=$2

    if [[ "$GITHUB_BUILD_TYPE" = "Release" ]]
    then
        BUILD_ID=${GITHUB_SHA::6}
        export TAG_NAME="v$GITHUB_INPUT_VERSION"
    else
        BUILD_ID="$GITHUB_BUILD_TYPE-${GITHUB_SHA::6}"
        export TAG_NAME=$BUILD_ID
    fi
else
    # Building locally
    BUILD_ID=Dev-$(git show --no-patch --format=format:"%h" --abbrev=6)

    # If there are uncommitted changes, add a marker to the string.
    if [[ -n $(git status --porcelain) ]]
    then
        BUILD_ID="${BUILD_ID}*"
    fi
fi

# If the commit string doesn't change, don't rewrite the file to avoid useless rebuilds.
new_content="#define BUILD_ID \"$BUILD_ID\""
old_content="$(cat source/build_id.h 2> /dev/null || true)"
if [[ "$new_content" != "$old_content" ]]
then
    echo "$new_content" > source/build_id.h
fi
