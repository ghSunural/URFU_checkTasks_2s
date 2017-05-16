//using namespace std;

template <class T>
class AbstractFactory {
	//factory, singleton
private:
	AbstractFactory() {

	}

	AbstractFactory(const AbstractFactory&) {};
	friend AbstractFactory& operator=(AbstractFactory&) {};

	~AbstractFactory() {

	}

public:

	static AbstractFactory& getInstance() {
		static AbstractFactory factoryInstance;
		return factoryInstance;
	}

	static T* create() {
		T* object = new T();
		return object;
	}

};