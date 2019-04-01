// constants definition
#define RATE 1600			// samples per second

// data structures
struct WAVHDR{
	char ChunkID[4]; // it has to be "RIFF"
	int ChunkSize;		// 4 - bytes number
	char Format[4];		// it has to be "WAVE"

	char Subchunk1ID[4];		// "fmt"
	int Subchunk1Size;		// PCM = 16
	short AudioFormat;		// should be 1
	short NumChannels;		// should be 1 for mono
	int SampleRate;			// 1600
	int ByteRate;			// 1600*NumChannels*BitsPerSample/8
	short BlockAlign;		// NumChannels*BitsPerSample/8
	short BitPerSample;		// in our app, 16 (S16_LE)

	char SubChunk2ID[4];	// "data"
	int SubCHunk2Size;		//
};
// function declarations
