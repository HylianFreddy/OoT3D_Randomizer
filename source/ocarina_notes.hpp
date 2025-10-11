#include <string>
#include "../code/src/ocarina_notes.h"

#define FROG_SONG_LENGTH 14

extern const std::array<std::string, OCARINA_BUTTON_MAX> ocarinaBtnChars;
extern const std::array<std::string, OCARINA_SONG_MAX> ocarinaSongNames;

extern OcarinaSongButtonSequence rSongData[OCARINA_SONG_MAX];
extern u8 rSongRequiredButtons[OCARINA_SONG_MAX];
extern u8 rFrogSongNotes[FROG_SONG_LENGTH];

void GenerateSongList(void);
