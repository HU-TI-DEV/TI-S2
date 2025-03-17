# todo.py

tasks = []

def show_tasks():
    if not tasks:
        print("Geen taken gevonden.")
    else:
        print("Takenlijst:")
        for index, task in enumerate(tasks, 1):
            print(f"{index}. {task}")

def main():
    print("Welkom bij de To-Do applicatie")
    show_tasks()

if __name__ == "__main__":
    main()