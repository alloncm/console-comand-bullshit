
#include"Database.h"
#include<fstream>
#include<random>
#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace alloncm;

int Min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}
void usingDb()
{
	char c = 0;
	Database newData;
	Database loadData;
	while (c != 'e')
	{
		print("(l)oad (s)ave (a)dd (p)rint or (e)xit?\n");
		char a = getchar();
		getchar();
		int b;
		switch (a)
		{
		case 'l':
			loadData.Load("derp.txt");
			print("load complete\n");
			break;
		case 's':
			newData.Save("derp.txt", loadData);
			print("save complete\n");
			break;
		case 'a':
			print("enter a name\n");
			char buf[10];
			GetStr(buf, 10);
			char instr[10];
			print("enter a number\n");
			GetStr(instr, 10);
			b = str2int(instr);
			newData.Add(buf, b);
			break;
		case 'p':
			loadData.Print();
			newData.Print();
			break;
		case 'e':
			c = a;
			break;
		}
	}
}
std::vector<int> FillBuckets(const std::string& word)
{
	std::vector<int> buckets(26, 0);
	for (char c : word)
	{
		buckets[c - 'a']++;
	}
	return buckets;
}
int Score(std::string word, std::string guess)
{
	const auto buckets1 = FillBuckets(word);
	const auto buckets2 = FillBuckets(guess);

	int score = 0;
	for (int i = 0; i < 26; i++)
	{
		score += Min(buckets1[i], buckets2[i]);
	}
	
	for (int i = 0; i < 5; i++)
	{
		if (word[i] == guess[i])
		{
			score++;
		}
	}
	return score;
}

bool DoesWordExist(const std::vector<std::string>& vec, const std::string word)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].compare(word)==0)
		{
			return true;
		}
	}
	return false;

}

std::vector<std::string> GetFiveWords(std::string source)
{
	std::vector<std::string> words;
	std::ifstream in(source);

	for (std::string line; std::getline(in, line);)
	{
		if (!line.empty() && line.size() == 5)
		{
			words.push_back(line);
		}
		else
		{
			continue;
		}
	}
	in.close();
	return words;
}

std::vector<std::string> Intersection(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2)
{
	std::vector<std::string> inter;
	for (const auto& w : vec1)
	{
		if (DoesWordExist(vec2, w))
		{
			inter.push_back(w);
		}
	}
	return inter;
}
int main()
{
	std::vector<std::string> common_five_words = GetFiveWords("20k.txt");
	std::vector<std::string> all_five_words = GetFiveWords("sgb-words.txt");

	auto five_words = Intersection(common_five_words, all_five_words);
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int>dist(0, five_words.size() - 1);
	const std::string target = five_words[dist(rng)];

	std::string guess;
	
	int score = 0;
	do
	{
		std::cout << "guess a word with 5 letters" << std::endl;
		std::getline(std::cin, guess);
		for (auto& c : guess)
		{
			c = std::tolower(c);
		}
		while (DoesWordExist(all_five_words, guess) == false)
		{
			std::cout << "you dumd fuck enter a word" << std::endl;
			std::cout << "guess a word with 5 letters" << std::endl;
			std::getline(std::cin, guess);
		}
		score = Score(target, guess);
		std::cout << "your score was " << score << std::endl;
		if (score == 10)
		{
			std::cout << "congratulation you guessed corectly" << std::endl;
		}
		else
		{
			std::cout << "too bad you dumd fuck" << std::endl;
		}
	} while (score != 10);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}