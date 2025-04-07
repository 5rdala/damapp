#include <raylib.h>

#include "button_click.h"

static Sound click_sound = {};

void LoadSounds(void)
{
	// button click sound
	Wave click_wave = LoadWaveFromMemory(".wav", button_click_wav, button_click_wav_len);
	click_sound = LoadSoundFromWave(click_wave);
	UnloadWave(click_wave);
}

void UnLoadSounds(void)
{
	// unload button click sound
	UnloadSound(click_sound);
}

Sound *GetClickSound(void)
{
	return &click_sound;
}
