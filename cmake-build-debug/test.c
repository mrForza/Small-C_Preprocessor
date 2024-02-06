#include  <stdio.h> // Подключение библиотеки ввода-вывода

// Some comments
void swap(int* px, int* py) {
    int temp = *px;
    *px = *py;
    // Мы должны свапнуть два числа с помощью указателей
    *py = temp;
}


int main()         // Главная функция
{
    printf("Hello, world!"); // Вывод сообщения
    getchar();               // Задержка окна консоли
    return 0;
} // Lorem ipsum doler sit amet