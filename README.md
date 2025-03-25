# Коллоквиум по предмету "Операционные системы"
Жерносек Даниил, 11 группа, нечетный вариант 3


## Ответ на "нулевой" вопросы
Ответ на нулевые вопросы в файле [answer_first.docx](https://github.com/ddjoul/lab2-task1-gr11-zharnasek/blob/master/answer_first.docx).

## Ответ на "основные" вопросы
Ответ на основные вопросы в файле [answer_second.docx](https://github.com/ddjoul/lab2-task1-gr11-zharnasek/blob/master/answer_second.docx).

## Задачи
Код задач находится в папке [problems](https://github.com/ddjoul/Colloquium_OS/tree/master/problems).

**Генерация факториалов**
- Генерирует первые n факториалов с защитой от переполнения.
- Интерфейс:
```c++
static std::vector<unsigned long long> FactorialGenerator::generate(unsigned int n);
```

**Удаление дубликатов**
- Удаляет дубликаты из контейнера, сохраняя порядок элементов.
- Интерфейс:
```c++
template <typename T>
static std::vector<T> DuplicateRemover<T>::removeDuplicates(const std::vector<T>& input); 
```

**Разворот связного списка**
- Генерирует первые n факториалов с защитой от переполнения.
- Интерфейс:
```c++
static ListNode* ListReverser::reverse(ListNode* head);
```

**Сборка и тестирование**
- Сборка проекта:
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

- Запуск примеров:
```bash
./build/tasks_app
```

- Запуск тестов:
```bash
cd build
ctest --output-on-failure
```