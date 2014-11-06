#pragma once
class Randomizer
{




public:

	~Randomizer();



	static Randomizer& Instance()
	{
		static Randomizer mInstance;
		return mInstance;
	}

	int generateRandomRow(int rowMaximumValue);
	int generateRandomCollumn(int collumnMaximumValue);
	int generateRandomNumber(int maximumNumber);




private:
	Randomizer(){}

	Randomizer(Randomizer const&);
	void operator=(Randomizer const&);

};

