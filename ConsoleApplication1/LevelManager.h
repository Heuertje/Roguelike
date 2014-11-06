#pragma once
class LevelManager
{
public:

	int currentLevel = 0;
	 

	static LevelManager& Instance()
	{
		static LevelManager mInstance;
		return mInstance;
	}

	int GetCurrentLevel();
	void SetCurrentLevel(int newLevel);


	~LevelManager();


private:
	LevelManager(){}

	LevelManager(LevelManager const&);
	void operator=(LevelManager const&);

	





};

