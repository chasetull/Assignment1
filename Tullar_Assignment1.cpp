/*
Chase Tullar
2297037
CPSC350
Rene German
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <cctype>
using namespace std;

float calcVariance(string lineIn, float m)
{
	float lineSize = 0;
	float point;
	point = pow(lineIn.size() - m, 2);
	lineSize += point;

	return lineSize;
}
//function for variance

int main()
{
	float returnV;
	float returnCount;

	char a = 'A';
	char c = 'C';
	char t = 'T';
	char g = 'G';
	//vars to check for ATCG

	int counterA = 0;
	int counterC = 0;
	int counterT = 0;
	int counterG = 0;
	float counterTotal = 0;
	int counterSize = 0;
	float fileSize = 0;
	float counterMean = 0;
	int counterBigram = 0;
	//counter ints for ATCG

	float counterAa = 0;
	float counterAc = 0;
	float counterAg = 0;
	float counterAt = 0;
	//A
	float counterCa = 0;
	float counterCc = 0;
	float counterCg = 0;
	float counterCt = 0;
	//C
	float counterGa = 0;
	float counterGc = 0;
	float counterGg = 0;
	float counterGt = 0;
	//G
	float counterTa = 0;
	float counterTc = 0;
	float counterTg = 0;
	float counterTt = 0;
	//T
	//var for double chars counter

	float probA = 0;
	float probC = 0;
	float probT = 0;
	float probG = 0;
	//single var probability

	float probAa = 0;
	float probAc = 0;
	float probAg = 0;
	float probAt = 0;
	//Aa probability
	float probCa = 0;
	float probCc = 0;
	float probCg = 0;
	float probCt = 0;
	//Cc probability
	float probGa = 0;
	float probGc = 0;
	float probGg = 0;
	float probGt = 0;
	//Gg probability
	float probTa = 0;
	float probTc = 0;
	float probTg = 0;
	float probTt = 0;
	//Tt probability

	string line;
	string word;
	string filePath;
	float varFinal = returnCount / fileSize;
	//retreival vars

	cout << "Enter the path for the file you want to process(dna.txt): " << endl;
	cin >> filePath;

	while(filePath != "dna.txt")
	{
		cout << "Error from input, try new path: " << endl;
		cin >> filePath;
	}
	//check for right file path

	fstream dnaFile (filePath);
	//create file stream
	

	if (dnaFile.good())
	{


		while (getline (dnaFile, line))
		{
			counterSize = counterSize + line.size();
			++ fileSize;
			//counting line sizes and total lines
			

			for (int i = 0; i < line.size(); i++)
			{
				
				if (line[i] == a || line[i] == 'a')
				{
					++ counterA;
					toupper(line[i]);
					
				}

				else if (line[i] == c || line[i] == 'c')
				{
					++ counterC;
					toupper(line[i]);
					
				}

				else if (line[i] == t || line[i] == 't')
				{
					++ counterT;
					toupper(line[i]);
					
				}

				else if (line[i] == g || line[i] == 'g')
				{
					++ counterG;
					toupper(line[i]);
					
				}

				else 
				{
					cout << "No " << line << " should exist. " << endl;

					//Delete char
				}
				//single char comparing

				if (line[i] == a && line[i+1] == a)
				{
					++ counterAa;
					++ counterBigram;
				}
				if (line[i] == a && line[i+1] == c)
				{
					++ counterAc;
					++ counterBigram;
				}
				if (line[i] == a && line[i+1] == g)
				{
					++ counterAg;
					++ counterBigram;
				}
				if (line[i] == a && line[i+1] == t)
				{
					++ counterAt;
					++ counterBigram;
				}
				//Aa
				if (line[i] == c && line[i+1] == a)
				{
					++ counterCa;
					++ counterBigram;
				}
				if (line[i] == c && line[i+1] == c)
				{
					++ counterCc;
					++ counterBigram;
				}
				if (line[i] == c && line[i+1] == g)
				{
					++ counterCg;
					++ counterBigram;
				}
				if (line[i] == c && line[i+1] == t)
				{
					++ counterCt;
					++ counterBigram;
				}
				//Cc
				if (line[i] == g && line[i+1] == a)
				{
					++ counterGa;
					++ counterBigram;
				}
				if (line[i] == g && line[i+1] == c)
				{
					++ counterGc;
					++ counterBigram;
				}
				if (line[i] == g && line[i+1] == g)
				{
					++ counterGg;
					++ counterBigram;
				}
				if (line[i] == g && line[i+1] == t)
				{
					++ counterGt;
					++ counterBigram;
				}
				//Gg
				if (line[i] == t && line[i+1] == a)
				{
					++ counterTa;
					++ counterBigram;
				}
				if (line[i] == t && line[i+1] == c)
				{
					++ counterTc;
					++ counterBigram;
				}
				if (line[i] == t && line[i+1] == g)
				{
					++ counterTg;
					++ counterBigram;
				}
				if (line[i] == t && line[i+1] == t)
				{
					++ counterTt;
					++ counterBigram;
				}
				//Tt
				//double var comparing

			}

			
		}

		counterMean = counterSize / fileSize;

		dnaFile.clear();
		dnaFile.seekg(0, dnaFile.beg);


		while (getline (dnaFile, line))
		{
			returnV = calcVariance(line, counterMean);
			returnCount += returnV;
		}

		varFinal = returnCount / fileSize;
		//calculating the final Variance

		dnaFile.close();
		//close file

		counterTotal = counterA + counterC + counterT + counterG;
		//calculate total
		
		//calculate mean
		probA = counterA / counterTotal * 100;
		probC = counterC / counterTotal * 100;
		probT = counterT / counterTotal * 100;
		probG = counterG / counterTotal * 100;
		//calculating char probability

		probAa = counterAa / counterBigram * 100;
		probAc = counterAc / counterBigram * 100;
		probAg = counterAg / counterBigram * 100;
		probAt = counterAt / counterBigram * 100;
		//calculating Aa bigrams
		probCa = counterCa / counterBigram * 100;
		probCc = counterCc / counterBigram * 100;
		probCg = counterCg / counterBigram * 100;
		probCt = counterCt / counterBigram * 100;
		//calculating Aa bigrams
		probGa = counterGa / counterBigram * 100;
		probGc = counterGc / counterBigram * 100;
		probGg = counterGg / counterBigram * 100;
		probGt = counterGt / counterBigram * 100;
		//calculating Aa bigrams
		probTa = counterTa / counterBigram * 100;
		probTc = counterTc / counterBigram * 100;
		probTg = counterTg / counterBigram * 100;
		probTt = counterTt / counterBigram * 100;
		//calculating Aa bigrams

		// float valuesV = counterTotal - (counterMean * fileSize);
		// float variance = pow(valuesV, 2);
		//variance calc


		cout << "G count: " << counterG << endl;
		cout << "T count: " << counterT << endl;
		cout << "C count: " << counterC << endl;
		cout << "A count: " << counterA << endl;
		//cout << "Total amnt of characters: " << counterTotal << endl;
		
		//print amount of each char and total
		cout << "Probability of A: " << probA << "%" << endl;
		cout << "Probability of C: " << probC << "%" << endl;
		cout << "Probability of T: " << probT << "%" << endl;
		cout << "Probability of G: " << probG << "%" << endl;
		//print probability

		cout << "Sum of length: " << counterSize << endl;
		cout << "Mean of length: " << counterMean << endl;
		//mean / sum / standard deviation / variance

		cout << "AA count: " << counterAa << endl;
		cout << "AC count: " << counterAc << endl;
		cout << "AG count: " << counterAg << endl;
		cout << "AT count: " << counterAt << endl;
		//printing amount of A bigrams
		cout << "CA count: " << counterCa << endl;
		cout << "CC count: " << counterCc << endl;
		cout << "CG count: " << counterCg << endl;
		cout << "CT count: " << counterCt << endl;
		//printing amount of C bigrams
		cout << "GA count: " << counterGa << endl;
		cout << "GC count: " << counterGc << endl;
		cout << "GG count: " << counterGg << endl;
		cout << "GT count: " << counterGt << endl;
		//printing amount of G bigrams
		cout << "TA count: " << counterTa << endl;
		cout << "TC count: " << counterTc << endl;
		cout << "TG count: " << counterTg << endl;
		cout << "TT count: " << counterTt << endl;
		//printing amount of T bigrams

		cout << "Probability of AA: " << probAa << "%" << endl;
		cout << "Probability of AC: " << probAc << "%" << endl;
		cout << "Probability of AG: " << probAg << "%" << endl;
		cout << "Probability of AT: " << probAt << "%" << endl;
		//printing probability of A bigrams
		cout << "Probability of CA: " << probCa << "%" << endl;
		cout << "Probability of CC: " << probCc << "%" << endl;
		cout << "Probability of CG: " << probCg << "%" << endl;
		cout << "Probability of CT: " << probCt << "%" << endl;
		//printing probability of C bigrams
		cout << "Probability of GA: " << probGa << "%" << endl;
		cout << "Probability of GC: " << probGc << "%" << endl;
		cout << "Probability of GG: " << probGg << "%" << endl;
		cout << "Probability of GT: " << probGt << "%" << endl;
		//printing probability of G bigrams
		cout << "Probability of TA: " << probTa << "%" << endl;
		cout << "Probability of TC: " << probTc << "%" << endl;
		cout << "Probability of TG: " << probTg << "%" << endl;
		cout << "Probability of TT: " << probTt << "%" << endl;
		//printing probability of T bigrams

		cout << "Variance: " << returnCount << endl;
		cout << "Standard Deviation: " << varFinal << endl;
		//printing variance and SD

	}

	else
	{
		cout << "File corrupted.";
		exit(0);
	}
	//if dna.txt doesn't open

	fstream outputFile ("chaseTullar.txt");
	//create my file to send data

	if (outputFile.is_open())
	{
		outputFile << "Chase Tullar \n" << "2297037 \n" << "CPSC350 \n" << "Tullar_Assignment1 \n" << endl;
		//printing header

		outputFile << "G count: " << counterG << endl;
		outputFile << "T count: " << counterT << endl;
		outputFile << "C count: " << counterC << endl;
		outputFile << "A count: " << counterA << endl;
		//cout << "Total amnt of characters: " << counterTotal << endl;
		
		//print amount of each char and total
		outputFile << "Probability of A: " << probA << "%" << endl;
		outputFile << "Probability of C: " << probC << "%" << endl;
		outputFile << "Probability of T: " << probT << "%" << endl;
		outputFile << "Probability of G: " << probG << "%" << endl;
		//print probability

		outputFile << "Sum of length: " << counterSize << endl;
		outputFile << "Mean of length: " << counterMean << endl;
		//mean / sum / standard deviation / variance

		outputFile << "AA count: " << counterAa << endl;
		outputFile << "AC count: " << counterAc << endl;
		outputFile << "AG count: " << counterAg << endl;
		outputFile << "AT count: " << counterAt << endl;
		//printing amount of A bigrams
		outputFile << "CA count: " << counterCa << endl;
		outputFile << "CC count: " << counterCc << endl;
		outputFile << "CG count: " << counterCg << endl;
		outputFile << "CT count: " << counterCt << endl;
		//printing amount of C bigrams
		outputFile << "GA count: " << counterGa << endl;
		outputFile << "GC count: " << counterGc << endl;
		outputFile << "GG count: " << counterGg << endl;
		outputFile << "GT count: " << counterGt << endl;
		//printing amount of G bigrams
		outputFile << "TA count: " << counterTa << endl;
		outputFile << "TC count: " << counterTc << endl;
		outputFile << "TG count: " << counterTg << endl;
		outputFile << "TT count: " << counterTt << endl;
		//printing amount of T bigrams

		outputFile << "Probability of AA: " << probAa << "%" << endl;
		outputFile << "Probability of AC: " << probAc << "%" << endl;
		outputFile << "Probability of AG: " << probAg << "%" << endl;
		outputFile << "Probability of AT: " << probAt << "%" << endl;
		//printing probability of A bigrams
		outputFile << "Probability of CA: " << probCa << "%" << endl;
		outputFile << "Probability of CC: " << probCc << "%" << endl;
		outputFile << "Probability of CG: " << probCg << "%" << endl;
		outputFile << "Probability of CT: " << probCt << "%" << endl;
		//printing probability of C bigrams
		outputFile << "Probability of GA: " << probGa << "%" << endl;
		outputFile << "Probability of GC: " << probGc << "%" << endl;
		outputFile << "Probability of GG: " << probGg << "%" << endl;
		outputFile << "Probability of GT: " << probGt << "%" << endl;
		//printing probability of G bigrams
		outputFile << "Probability of TA: " << probTa << "%" << endl;
		outputFile << "Probability of TC: " << probTc << "%" << endl;
		outputFile << "Probability of TG: " << probTg << "%" << endl;
		outputFile << "Probability of TT: " << probTt << "%" << endl;
		//printing probability of T bigrams

		outputFile << "Variance: " << returnCount << endl;
		outputFile << "Standard Deviation: " << varFinal << endl;
		//printing variance and SD


		outputFile.close();
	}
	//printing data to file chaseTullar.txt

	
	//math for D
	int counting = 0;

	

	while (counting < 1001)
	{
		double x = rand() / (double) RAND_MAX;
		double y = rand() / (double) RAND_MAX;
		double strChar = rand() / (double) RAND_MAX;
		//2 random numbers a and b
		
		float l = sqrt(-2 * log(x));
		l = l * (cos(2 * y * M_PI));
		//math for constant C

		float d = (l * varFinal) + counterMean;

		string dnaString;

		for (int i = 0; i < d; i++)
		{

			if (strChar < 0.18)
			{
				dnaString += 'A';
			}

			else if (strChar > 0.18)
			{
				dnaString += 'T';
			}

			else if (strChar > .27 && strChar < .36)
			{
				dnaString += 'G';
			}

			else if (strChar > .36)
			{
				dnaString += 'C';
			}
		}

		cout << dnaString << endl;

		++ counting;
		strChar = rand() / (double) RAND_MAX;
		y = rand() / (double) RAND_MAX;
		x = rand() / (double) RAND_MAX;
	}


}