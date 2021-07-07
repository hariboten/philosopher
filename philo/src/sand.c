#include <stdlib.h>

//関数の宣言
void	function(void *hoge)
{
	return ;
}

//関数ポインタを返す関数の宣言
void	(*function_that_return_function_pointer(void *hoge))(void *huge)
{
	return (function);
}

//関数ポインタを返す関数のポインタを返す関数の宣言
void	(*(*function_that_return_pointer_of_function_that_return_function_pointer(void *hoge))(void *huga))(void *hogege)
{
	return (function_that_return_function_pointer);
}

void	(*function1(void *hoge))(void *huge);
void	(*function2(void *hoge))(void *huge);
void	(*function3(void *hoge))(void *huge);

void	(*function1(void *hoge))(void *huge)
{
	return (function2);
}

void	(*function2(void *hoge))(void *huge)
{
	return (function3);
}

void	(*function3(void *hoge))(void *huge)
{
	return (function1);
}

int		main()
{
	void (*function_pointer)(void *); //関数ポインタの型の宣言
	void (*function_pointer_that_return_function_pointer(void *))(void *); //関数ポインタを返す関数のポインタの型の宣言
	void (*(*function_pointer_that_return_pointer_of_function_that_return_function_pointer(void *))(void *))(void *);//関数ポインタを返す関数のポインタを返す関数のポインタの宣言

	while (1)
	{
		function_pointer_that_return_function_pointer = function_pointer_that_return_function_pointer(NULL);
	}
}
