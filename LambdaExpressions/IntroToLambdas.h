#pragma once

template<typename T, int size>
void Sort(T(&arr)[size]) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}
	}
		
}
// create a comparator predicate
using Comparator = bool(*)(int, int); 
template<typename T, int size>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++) {
			if (comp( arr[j] , arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);

			}
		}
	}

}
/// <summary>
/// to eliminate creating copies when swapping, replace by value assignment in the swap logic to use 
/// std::move
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
template<typename T, int size>
void SortWithMoveSemantics(T(&arr)[size]) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = std::move( arr[j]);
				arr[j] = std::move( arr[j + 1]);
				arr[j + 1] = std::move(temp);

			}
		}
	}

}


// function objects
struct CompStruct {
	bool operator()(int x, int y) {
		return x > y;
	}
};

// sorting with comparator template
// create a comparator predicate
//using Comparator = bool(*)(int, int);
template<typename T, int size, typename ComparartorUnknown>
void Sort(T(&arr)[size], ComparartorUnknown comp) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);

			}
		}
	}

}

// 

struct SumObject {
	double operator() (double x, double y) const {
		return x + y;
	}
};

//for each consumer
template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback callback) {
	for (int i = 0; i < size; i++) {
		callback(arr[i]);
	}
}

class Product {
	std::string name;
	float price;
public:
	Product(const std::string & n, float p) : name(n), price(p) {}
	void AssignFinalPrice() {
		float taxes[]{ 12,5,5 };
		float basePrice{ price };
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			price += taxedPrice;
			});
	}
};



