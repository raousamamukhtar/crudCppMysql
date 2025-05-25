#include <iostream>
#include <mysql.h>
#include <string>

using namespace std;

class UserDB {
private:
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

public:
    UserDB() {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "12345", "pro1", 0, NULL, 0);
        if (conn)
            cout << " Connected to MySQL Database successfully.\n";
        else {
            cout << "❌ Failed to connect: " << mysql_error(conn) << endl;
            exit(1);
        }
    }

    void createUser(string name, string email) {
        string query = "INSERT INTO user(name, email) VALUES('" + name + "', '" + email + "')";
        if (mysql_query(conn, query.c_str()))
            cout << " Insert failed: " << mysql_error(conn) << endl;
        else
            cout << " User added successfully.\n";
    }

    void readUsers() {
        if (mysql_query(conn, "SELECT * FROM user")) {
            cout << " Select failed: " << mysql_error(conn) << endl;
            return;
        }
        res = mysql_store_result(conn);
        cout << "📋 User Records:\n";
        while ((row = mysql_fetch_row(res))) {
            cout << "ID: " << row[0] << " | Name: " << row[1] << " | Email: " << row[2] << endl;
        }
        mysql_free_result(res);
    }

    void updateUser(int id, string name, string email) {
        string query = "UPDATE user SET name='" + name + "', email='" + email + "' WHERE id=" + to_string(id);
        if (mysql_query(conn, query.c_str()))
            cout << " Update failed: " << mysql_error(conn) << endl;
        else
            cout << " User updated successfully.\n";
    }

    void deleteUser(int id) {
        string query = "DELETE FROM user WHERE id=" + to_string(id);
        if (mysql_query(conn, query.c_str()))
            cout << " Delete failed: " << mysql_error(conn) << endl;
        else
            cout << " User deleted successfully.\n";
    }

    ~UserDB() {
        mysql_close(conn);
    }
};

int main() {
    UserDB db;
    int choice, id;
    string name, email;

    do {
        cout << "\n--- USER MANAGEMENT ---\n";
        cout << "1. Create User\n2. Read Users\n3. Update User\n4. Delete User\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin.ignore(); getline(cin, name);
            cout << "Enter email: ";
            getline(cin, email);
            db.createUser(name, email);
            break;
        case 2:
            db.readUsers();
            break;
        case 3:
            cout << "Enter user ID to update: ";
            cin >> id;
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new email: ";
            getline(cin, email);
            db.updateUser(id, name, email);
            break;
        case 4:
            cout << "Enter user ID to delete: ";
            cin >> id;
            db.deleteUser(id);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "❗ Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
