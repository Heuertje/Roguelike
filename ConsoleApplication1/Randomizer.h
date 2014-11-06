#pragma once
class Randomizer
{
public:

	static Randomizer& Instance()
	{
		static Randomizer mInstance;
		return mInstance;
	}
	~Randomizer();



	int generateRandomRow(int rowMaximumValue);
	int generateRandomCollumn(int collumnMaximumValue);
	int generateRandomNumber(int maximumNumber);




private:
	Randomizer(){}
	Randomizer(Randomizer const&);
	void operator=(Randomizer const&);

};

