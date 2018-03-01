#include <iostream> 
#include <fstream> 
#include <vector> 
#include <cmath> 
#include <cassert> 

using namespace std; 

struct Map { 
	vector<int> key; 
	vector<int> value; 
	Map(){} 
	Map(int n) { 
		assert(n > 0); 
		for (int i = 0; i < n; ++i) { 
			key.push_back(i); 
			value.push_back(i); 
		} 
	} 
	void setN(int n) { 
		key.clear(); 
		value.clear(); 
		for (int i = 0; i < n; ++i) { 
			key.push_back(i); 
			value.push_back(i); 
		} 
	} 
}; 

class E { 
	private: 
		Map map; 
		int n; 
	public: 
		E(){} 
		explicit E(int n) { 
			map.setN(n); 
			this->n = n; 
		} 
		static int random(int n) { 
			assert(n > 0); 
			return rand()%n; 
		} 
		void shuffle() { 
			for (int i = 0; i < n; ++i) { 
				int index = random(n); 
				int temp = map.value[i]; 
				map.value[i] = map.value[index]; 
				map.value[index] = temp; 
			} 
		} 
		void shuffle(int shuffleTimes) { 
			for (int i = 0; i < shuffleTimes; ++i) { shuffle(); } 
		} 
		bool noneMatched() const { 
			for (int i = 0; i < n; ++i) { 
				if (map.key[i] == map.value[i]) return false; 
			} 
			return true; 
		} 
		double sweep() { 
			int N = 1000; 
			int count = 0; 
			int shuffleTimes = 40; 
			for (int i = 0; i < N; ++i) { 
				shuffle(shuffleTimes); 
				if (noneMatched()) count++; 
			}
			return float(count)/float(N); 
		}
		static double mean(const vector<double> &myVector) { 
			assert(myVector.size() > 0); 
			double s = 0.0; 
			for (int i = 0; i < myVector.size(); ++i) { 
				s = s + myVector[i]; 
			} 
			return s/float(myVector.size()); 
		} 
		static double sigma(const vector<double> &myVector) { 
			assert(myVector.size() > 1); 
			double mu = mean(myVector); 
			double s = 0.0; 
			for (int i = 0; i < myVector.size(); ++i) { 
				s = s + (myVector[i] - mu)*(myVector[i] - mu); 
			} 
			return sqrt(s/float(myVector.size()-1));
		} 
		double getFrequency() { 
			vector<double> frequencies; 
			int sweepTimes = 100; 
			for (int i = 0; i < sweepTimes; ++i) { 
				double f = sweep(); 
				cout << i << " " << sweepTimes << " " << f << endl; 
				frequencies.push_back(f); 
			} 
			return mean(frequencies); 
		} 
		double getEulerConstant() { 
			return 1.0/getFrequency(); 
		} 
}; 

int main(int argc, char **argv) { 
	int sampleNumber = 300; 
	E machine(sampleNumber); 
	cout << machine.getEulerConstant() << endl; 
	return 0; 
}
