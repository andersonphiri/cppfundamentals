#include <stdio.h>
#include <stdlib.h>

int Run() {
	int* p = malloc(sizeof(int)); // creates a void pointer which is auto casted since we are in c not c++. malloc does not initialize the memory but calloc does

	if (p == NULL)
	{
		printf("Failed to allocate memory for p!!! \n");
		return -1;
	}
	*p = 349;
	printf("%d", *p);
	free(p); 
	p = NULL;
	free(p);

	// calloc example
	int* q = calloc(1, sizeof(int)); // unlike malloc, calloc initializes memory to 0
	if (q == NULL)
	{
		printf("Failed to allocate memory for q!!! \n");
		return -1;
	}
	*q = 349;
	printf("%d", *q);
	free(q);
	q = NULL;
	free(q);
	// creating memory for arrays using malloc:
	int* pArray = malloc(5 * sizeof(int));
	if (pArray == NULL)
	{
		printf("Failed to allocate memory for pArray!!! \n");
		return -1;
	}
	free(pArray);
	pArray = NULL;

	// creating memory for arrays using calloc array count = 5:
	int* qArray = calloc(5, sizeof(int));;
	if (qArray == NULL)
	{
		printf("Failed to allocate memory for qArray!!! \n");
		return -1;
	}
	free(qArray);
	qArray = NULL;
	return 0;
}
// continue with memory management in c++
// https://subscription.packtpub.com/video/programming/9781800566668/p3/video3_2/dynamic-memory-allocation-part-ii-new-operator