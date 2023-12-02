# Small-C_Preprocessor
Препроцессор для языка программирования Small-C.
Данный проект является обязательным модулем для компилятора **Small-C --- RISC-V assembly**

## Основные функции препроцессора:
- Удаление однострочных и многострочных комментариев
- Сокращение лишних пробелов и переводов на новую строку
- Вставка содержимого заголовочных файлов через директиву __#include__
- Выполнение макроподстановки через директиву __#define__, __#undef__
- Выполнение условной компиляции __#if__, __#ifdef__, __#ifndef__, __#else__, __#elif__, __#endif__

## Технологии:
- C (11 стандарт)
- Cmake, Makefiles (для автоматизации сборки)
