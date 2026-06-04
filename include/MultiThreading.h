#pragma once
#include "GameObject.h"
#include <set>
#include <vector>
#include <list>
#include <thread>
#include <memory>
#include <chrono>
#include <future>
#include <iostream>

class MultiThreading 
{
private:
	std::thread threadA;
	std::future<bool> future;
	std::thread threadB;
	sf::Sprite StartSprite;
	sf::Sprite getSprite()
	{
		return StartSprite;
	}
	bool finishedLoading = false;
	int loadTime = 0;
	float f_progress = 0;
	bool assetsReady = false;
	std::mutex m_mutex;
	

public:
	void render(sf::RenderWindow& window);

	void Working()
	{
		
		int i = 0;
		while (i < 3)
		{
			//std::cout << "Processing 1" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			i++;
		}
	}
	bool MoreWorking()
	{
		
		int j = 0;
		while (j < 10)
		{
			//std::cout << "Processing 2" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			j++;
		}
		return true;
	}

	void loadAssets()
	{
		for(int i = 0; i < 100; ++i)
		{
			//std::cout << "Setting up assets..." << (i + 1) << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(40));

			std::unique_lock<std::mutex> lock(m_mutex);
			f_progress += 1.0f;
			lock.unlock();
		}
	
		assetsReady = true;
	}

	MultiThreading()
	{
		threadA = std::thread(&MultiThreading::Working, this);
		future = std::async(std::launch::async, &MultiThreading::MoreWorking, this);//Launch immediately
		threadB = std::thread(&MultiThreading::loadAssets, this);
	}
	~MultiThreading()
	{
		if (threadA.joinable())
		{
			threadA.join();
		}
	}

	float getProgress()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		return f_progress;
	}

};