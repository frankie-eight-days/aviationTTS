#include <iostream>
#include "AudioFile.h"
#include <vector>

AudioFile<double> audioFile;

/* 	printSamples
*
*	Prints samples from a specific channel onto the terminal
*	Meant for data visulization
*
*	@param	start	the number where sample prints should start
*	@param	number 	the number of samples that function prints
*	@param 	channel the channel which sample is taken from (0: left, 1: right)
*/
void printSamples(int start, int number, int channel);

/* 	splitToClips
*
*	Takes the input samples and splits it into clips of just "Talking"
*	Pre-processing for the FFT analysis
*
*	@param		audio 					The entire audio clip samples
*
*	@returns 	vector<vector<int>> 	Each element of this vector contains another vector of strictly talking samples
*/
std::vector<vector<int>> splitToClips(audioFile audio);

int main()
{

	audioFile.load("/home/francis/Documents/cpp/fft/audio.wav");

	printSamples(10000, audioFile.getNumSamplesPerChannel()/10, 0);

	return 0;
}

void printSamples(int start, int number, int channel)
{
	for(int i = start; i < number; i++)
	{
		std::cout << "Sample Number: " << i << " " << audioFile.samples[channel][i] << "\n";
	}

}