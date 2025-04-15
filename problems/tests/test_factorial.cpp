#include "../include/menu.h"
#include "../include/soldiers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void show_main_menu(sqlite3* db) {
    int choice = 0;
    
    while (1) {
        printf("\n=== СИСТЕМА УЧЕТА ВОЕННОСЛУЖАЩИХ ===\n");
        printf("1. Добавить военнослужащего\n");
        printf("2. Найти военнослужащего по ID\n");
        printf("3. Найти военнослужащих по фамилии\n");
        printf("4. Найти военнослужащих по званию\n");
        printf("5. Удалить военнослужащего\n");
        printf("6. Экспортировать фотографию\n");
        printf("7. Демонстрация режимов вставки (autocommit и 
транзакция)\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите число.\n");
            clear_input_buffer();
            continue;
        }
        
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                handle_add_soldier(db);
                break;
            case 2:
                handle_find_by_id(db);
                break;
            case 3:
                handle_find_by_last_name(db);
                break;
            case 4:
                handle_find_by_rank(db);
                break;
            case 5:
                handle_delete_soldier(db);
                break;
            case 6:
                handle_export_photo(db);
                break;
            case 7:
                handle_insert_modes(db);
                break;
            case 0:
                printf("Программа завершена.\n");
                return;
            default:
                printf("Неверный выбор. Пожалуйста, выберите число от 0 до 
7.\n");
        }
    }
}

void handle_add_soldier(sqlite3* db) {
    Soldier soldier;
    char photo_path[256];
    
    memset(&soldier, 0, sizeof(Soldier));
    
    printf("\n=== ДОБАВЛЕНИЕ НОВОГО ВОЕННОСЛУЖАЩЕГО ===\n");
    
    printf("Фамилия: ");
    scanf("%49s", soldier.last_name);
    
    printf("Имя: ");
    scanf("%49s", soldier.first_name);
    
    printf("Отчество: ");
    scanf("%49s", soldier.middle_name);
    
    printf("\nАдрес (полный, включая почтовый индекс): ");
    clear_input_buffer();
    fgets(soldier.address, sizeof(soldier.address), stdin);
    soldier.address[strcspn(soldier.address, "\n")] = '\0';
    
    printf("\nНациональность: ");
    scanf("%49s", soldier.nationality);
    
    printf("\nДата рождения (ГГГГ-ММ-ДД): ");
    scanf("%19s", soldier.birth_date);
    
    printf("\nДолжность: ");
    clear_input_buffer();
    fgets(soldier.position, sizeof(soldier.position), stdin);
    soldier.position[strcspn(soldier.position, "\n")] = '\0';
    
    printf("Звание: ");
    fgets(soldier.rank, sizeof(soldier.rank), stdin);
    soldier.rank[strcspn(soldier.rank, "\n")] = '\0';
    
    printf("Зарплата: ");
    scanf("%d", &soldier.salary);
    
    printf("Путь к файлу фотографии (оставьте пустым, если нет): ");
    clear_input_buffer();
    fgets(photo_path, sizeof(photo_path), stdin);
    photo_path[strcspn(photo_path, "\n")] = '\0';
    
    if (add_soldier_autocommit(db, &soldier, photo_path[0] ? photo_path : 
NULL) == 0) {
        printf("Военнослужащий успешно добавлен с ID %d\n", soldier.id);
    } else {
        printf("Ошибка при добавлении военнослужащего\n");
    }
}

void handle_find_by_id(sqlite3* db) {
    int id;
    Soldier soldier;
    
    printf("\n=== ПОИСК ВОЕННОСЛУЖАЩЕГО ПО ID ===\n");
    printf("Введите ID: ");
    
    if (scanf("%d", &id) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        clear_input_buffer();
        return;
    }
    
    clear_input_buffer();
    
    if (get_soldier_by_id(db, id, &soldier) == 0) {
        printf("\n--- ИНФОРМАЦИЯ О ВОЕННОСЛУЖАЩЕМ ---\n");
        printf("ID: %d\n", soldier.id);
        printf("ФИО: %s %s %s\n", soldier.last_name, soldier.first_name, 
soldier.middle_name);
        printf("Адрес: %s\n", soldier.address);
        printf("Национальность: %s\n", soldier.nationality);
        printf("Дата рождения: %s\n", soldier.birth_date);
        printf("Должность: %s\n", soldier.position);
        printf("Звание: %s\n", soldier.rank);
        printf("Зарплата: %d\n", soldier.salary);
        printf("Фото: %s\n", soldier.photo_size > 0 ? "Имеется" : 
"Отсутствует");
        
        if (soldier.photo) {
            free(soldier.photo);
        }
    } else {
        printf("Военнослужащий с ID %d не найден\n", id);
    }
}

void handle_find_by_last_name(sqlite3* db) {
    char last_name[50];
    
    printf("\n=== ПОИСК ВОЕННОСЛУЖАЩИХ ПО ФАМИЛИИ ===\n");
    printf("Введите фрагмент фамилии: ");
    
    scanf("%49s", last_name);
    clear_input_buffer();
    
    find_servicemen_by_last_name(db, last_name);
}

void handle_find_by_rank(sqlite3* db) {
    char rank[50];
    
    printf("\n=== ПОИСК ВОЕННОСЛУЖАЩИХ ПО ЗВАНИЮ ===\n");
    printf("Введите звание: ");
    
    clear_input_buffer();
    fgets(rank, sizeof(rank), stdin);
    rank[strcspn(rank, "\n")] = '\0';
    
    find_servicemen_by_rank(db, rank);
}

void handle_delete_soldier(sqlite3* db) {
    int id;
    
    printf("\n=== УДАЛЕНИЕ ВОЕННОСЛУЖАЩЕГО ===\n");
    printf("Введите ID военнослужащего для удаления: ");
    
    if (scanf("%d", &id) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        clear_input_buffer();
        return;
    }
    
    clear_input_buffer();
    
    delete_soldier_by_id(db, id);
}

void handle_export_photo(sqlite3* db) {
    int id;
    char output_path[256];
    
    printf("\n=== ЭКСПОРТ ФОТОГРАФИИ ===\n");
    printf("Введите ID военнослужащего: ");
    
    if (scanf("%d", &id) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        clear_input_buffer();
        return;
    }
    
    clear_input_buffer();
    
    printf("Введите путь для сохранения фотографии: ");
    fgets(output_path, sizeof(output_path), stdin);
    output_path[strcspn(output_path, "\n")] = '\0';
    
    export_photo(db, id, output_path);
}

void handle_insert_modes(sqlite3* db) {
    Soldier autocommit_soldier, transaction_soldier;
    char photo_path[256];
    int choice;
    
    printf("\n=== ДЕМОНСТРАЦИЯ РЕЖИМОВ ВСТАВКИ ===\n");
    printf("1. Режим autocommit (вставка построчно)\n");
    printf("2. Режим транзакции (вставка в транзакции)\n");
    printf("Выберите режим: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        clear_input_buffer();
        return;
    }
    
    clear_input_buffer();
    
    if (choice != 1 && choice != 2) {
        printf("Неверный выбор. Пожалуйста, выберите 1 или 2.\n");
        return;
    }
    
    memset(choice == 1 ? &autocommit_soldier : &transaction_soldier, 0, 
sizeof(soldier));
    Soldier* soldier = choice == 1 ? &autocommit_soldier : 
&transaction_soldier;
    
    printf("\n=== ДОБАВЛЕНИЕ ТЕСТОВОГО ВОЕННОСЛУЖАЩЕГО (%s) ===\n", 
           choice == 1 ? "autocommit" : "транзакция");
    
    printf("Фамилия: ");
    scanf("%49s", soldier->last_name);
    
    printf("Имя: ");
    scanf("%49s", soldier->first_name);
    
    printf("Отчество: ");
    scanf("%49s", soldier->middle_name);
    
    printf("\nАдрес (полный, включая почтовый индекс): ");
    clear_input_buffer();
    fgets(soldier->address, sizeof(soldier->address), stdin);
    soldier->address[strcspn(soldier->address, "\n")] = '\0';
    
    printf("\nНациональность: ");
    scanf("%49s", soldier->nationality);
    
    printf("\nДата рождения (ГГГГ-ММ-ДД): ");
    scanf("%19s", soldier->birth_date);
    
    printf("\nДолжность: ");
    clear_input_buffer();
    fgets(soldier->position, sizeof(soldier->position), stdin);
    soldier->position[strcspn(soldier->position, "\n")] = '\0';
    
    printf("Звание: ");
    fgets(soldier->rank, sizeof(soldier->rank), stdin);
    soldier->rank[strcspn(soldier->rank, "\n")] = '\0';
    
    printf("Зарплата: ");
    scanf("%d", &soldier->salary);
    
    printf("Путь к файлу фотографии (оставьте пустым, если нет): ");
    clear_input_buffer();
    fgets(photo_path, sizeof(photo_path), stdin);
    photo_path[strcspn(photo_path, "\n")] = '\0';
    
    if (choice == 1) {
        printf("\nДобавление в режиме autocommit...\n");
        if (add_soldier_autocommit(db, soldier, photo_path[0] ? photo_path 
: NULL) == 0) {
            printf("Военнослужащий успешно добавлен с ID %d\n", 
soldier->id);
        } else {
            printf("Ошибка при добавлении военнослужащего\n");
        }
    } else {
        printf("\nДобавление в режиме транзакции...\n");
        if (add_soldier_transaction(db, soldier, photo_path[0] ? 
photo_path : NULL) == 0) {
            printf("Военнослужащий успешно добавлен с ID %d\n", 
soldier->id);
        } else {
            printf("Ошибка при добавлении военнослужащего\n");
        }
    }
}
