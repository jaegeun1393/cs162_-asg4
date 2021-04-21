#ifndef GOLD
#define GOLD
using namespace std;
#include "event.hpp"

class Gold : public Event {
	protected:
		string message;
	public:
		Gold();
		~Gold();
		string get_message();
};
#endif
