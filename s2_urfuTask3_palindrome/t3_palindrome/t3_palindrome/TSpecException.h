#include <string>
using namespace std;

class TSpecException {
private:
	string errorMessage_;

public:
	TSpecException(string msg) {
		errorMessage_ = msg;
	}

	string getErrorMessage() {

		return errorMessage_;
	}
};