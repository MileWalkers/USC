// ITP 165 Sound Header
// WAV file code from Douglas Thain
// http://www3.nd.edu/~dthain/courses/cse20211/fall2013/wavfile/

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int WAVFILE_SAMPLES_PER_SECOND = 44100;
const int VOLUME = 20000;
const int FREQUENCY = 900;
const double PI = 3.14159265358979323846;

// Struct representing WAV header
struct wavfile_header
{
	char	riff_tag[4];
	int	riff_length;
	char	wave_tag[4];
	char	fmt_tag[4];
	int	fmt_length;
	short	audio_format;
	short	num_channels;
	int	sample_rate;
	int	byte_rate;
	short	block_align;
	short	bits_per_sample;
	char	data_tag[4];
	int	data_length;
};

// Output File
static FILE* gOutputFile = nullptr;

// Waveform data for short/long waveforms, and pause waveforms
static short gShortWave[WAVFILE_SAMPLES_PER_SECOND / 10];
static short gLongWave[WAVFILE_SAMPLES_PER_SECOND / 4];
static short gPause[WAVFILE_SAMPLES_PER_SECOND / 8];

// For musical notes
// I'm assuming we won't go over 5 second notes!
static short gNoteBuffer[WAVFILE_SAMPLES_PER_SECOND * 5];
static int gBeatsPerMin = 100;

void initSound()
{
	struct wavfile_header header;

	int samples_per_second = WAVFILE_SAMPLES_PER_SECOND;
	int bits_per_sample = 16;

	strncpy(header.riff_tag, "RIFF", 4);
	strncpy(header.wave_tag, "WAVE", 4);
	strncpy(header.fmt_tag, "fmt ", 4);
	strncpy(header.data_tag, "data", 4);

	header.riff_length = 0;
	header.fmt_length = 16;
	header.audio_format = 1;
	header.num_channels = 1;
	header.sample_rate = samples_per_second;
	header.byte_rate = samples_per_second*(bits_per_sample / 8);
	header.block_align = bits_per_sample / 8;
	header.bits_per_sample = bits_per_sample;
	header.data_length = 0;

	gOutputFile = fopen("out.wav", "w+b");

	fwrite(&header, sizeof(header), 1, gOutputFile);

	fflush(gOutputFile);

	// Initialize waveform data
	for (int i = 0; i < sizeof(gShortWave) / 2; i++)
	{
		double t = (double)i / WAVFILE_SAMPLES_PER_SECOND;

		gShortWave[i] = static_cast<short>(VOLUME*sin(FREQUENCY*t * 2 * PI));
	}

	for (int i = 0; i < sizeof(gLongWave) / 2; i++)
	{
		double t = (double)i / WAVFILE_SAMPLES_PER_SECOND;

		gLongWave[i] = static_cast<short>(VOLUME*sin(FREQUENCY*t * 2 * PI));
	}

	for (int i = 0; i < sizeof(gPause) / 2; i++)
	{
		gPause[i] = 0;
	}
}

void writeData(short data[], size_t length)
{
	fwrite(data, sizeof(short), length, gOutputFile);
}

void addMorseDot()
{
	writeData(gShortWave, sizeof(gShortWave) / 2);
	writeData(gPause, sizeof(gPause) / 2);
}

void addMorseDash()
{
	writeData(gLongWave, sizeof(gLongWave) / 2);
	writeData(gPause, sizeof(gPause) / 2);
}

void addMorsePause()
{
	writeData(gPause, sizeof(gPause) / 2);
	writeData(gPause, sizeof(gPause) / 2);

}

void setBPM(int bpm)
{
	gBeatsPerMin = bpm;
}

void addNote(double freq, double beats)
{
	int numSamples = static_cast<int>(beats / gBeatsPerMin * 60.0 * WAVFILE_SAMPLES_PER_SECOND);

	double theta = freq * 2 * PI;
	for (int i = 0; i < numSamples; i++)
	{
		double t = (double)i / WAVFILE_SAMPLES_PER_SECOND;

		gNoteBuffer[i] = static_cast<short>(VOLUME*sin(theta * t));
	}

	writeData(gNoteBuffer, numSamples);

	// Add a 1/10th of a quarter note pause
	numSamples = static_cast<int>(0.1 / gBeatsPerMin * 60.0 * WAVFILE_SAMPLES_PER_SECOND);
	for (int i = 0; i < numSamples; i++)
	{
		gNoteBuffer[i] = 0;
	}
	writeData(gNoteBuffer, numSamples);
}

void addC(double beats)
{
	addNote(523.25, beats);
}

void addCSharp(double beats)
{
	addNote(554.37, beats);
}

void addDFlat(double beats)
{
	addNote(554.37, beats);
}

void addD(double beats)
{
	addNote(587.33, beats);
}

void addDSharp(double beats)
{
	addNote(622.25, beats);
}

void addEFlat(double beats)
{
	addNote(622.25, beats);
}

void addE(double beats)
{
	addNote(659.25, beats);
}

void addF(double beats)
{
	addNote(698.46, beats);
}

void addFSharp(double beats)
{
	addNote(739.99, beats);
}

void addGFlat(double beats)
{
	addNote(739.99, beats);
}

void addG(double beats)
{
	addNote(783.99, beats);
}

void addGSharp(double beats)
{
	addNote(830.61, beats);
}

void addAFlat(double beats)
{
	addNote(830.61, beats);
}

void addA(double beats)
{
	addNote(880, beats);
}

void addASharp(double beats)
{
	addNote(932.33, beats);
}

void addBFlat(double beats)
{
	addNote(932.33, beats);
}

void addB(double beats)
{
	addNote(987.77, beats);
}

void addHighC(double beats)
{
	addNote(1046.50, beats);
}

void addHighCSharp(double beats)
{
	addNote(1108.73, beats);
}

void addHighDFlat(double beats)
{
	addNote(1108.73, beats);
}

void addHighD(double beats)
{
	addNote(1174.66, beats);
}

void addHighDSharp(double beats)
{
	addNote(1244.51, beats);
}

void addHighEFlat(double beats)
{
	addNote(1244.51, beats);
}

void addHighE(double beats)
{
	addNote(1318.51, beats);
}

void addHighF(double beats)
{
	addNote(1396.91, beats);
}

void addHighFSharp(double beats)
{
	addNote(1479.98, beats);
}

void addHighGFlat(double beats)
{
	addNote(1479.98, beats);
}

void addHighG(double beats)
{
	addNote(1567.98, beats);
}

void addHighGSharp(double beats)
{
	addNote(1661.22, beats);
}

void addHighAFlat(double beats)
{
	addNote(1661.22, beats);
}

void addHighA(double beats)
{
	addNote(1760.00, beats);
}

void addHighASharp(double beats)
{
	addNote(1864.66, beats);
}

void addHighBFlat(double beats)
{
	addNote(1864.66, beats);
}

void addHighB(double beats)
{
	addNote(1975.53, beats);
}

void addRest(double beats)
{
	addNote(0.0, beats);
}

void playSound()
{
	// Close the file
	int file_length = static_cast<int>(ftell(gOutputFile));

	int data_length = file_length - sizeof(struct wavfile_header);
	fseek(gOutputFile, sizeof(struct wavfile_header) - sizeof(int), SEEK_SET);
	fwrite(&data_length, sizeof(data_length), 1, gOutputFile);

	int riff_length = file_length - 8;
	fseek(gOutputFile, 4, SEEK_SET);
	fwrite(&riff_length, sizeof(riff_length), 1, gOutputFile);

	fclose(gOutputFile);

	// Play the file
#if _WIN32
	// On windows
	system("start out.wav");
#else
	// Mac
	system("afplay out.wav");
#endif
}
