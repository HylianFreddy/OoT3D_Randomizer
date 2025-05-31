#include <string>
#include "../code/src/ocarina_notes.h"

extern const std::array<std::string, OCARINA_BUTTON_MAX> ocarinaBtnChars;
extern const std::array<std::string, OCARINA_SONG_MAX> ocarinaSongNames;

extern OcarinaSongButtonSequence rSongData[OCARINA_SONG_MAX];
extern u8 rSongRequiredButtons[OCARINA_SONG_MAX];

void GenerateSongList(void);
