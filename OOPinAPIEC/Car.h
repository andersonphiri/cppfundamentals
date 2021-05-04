
class Car
{
public:
	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassenger(int count);
	Car(float amount, int pass);
	void Dashboard() const;
	void Foo(const Car& car);
	static void ShowCount();
	Car();
	Car(float amount);
	~Car();


private:
	float fuel{10};
	float speed{ 0 };
	int passengers{1};
	static int totalCount;
};

struct Point
{
	float x;
	float y;
};
