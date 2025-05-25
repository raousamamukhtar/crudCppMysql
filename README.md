# 🚀 C++ MySQL DB connection 

This project connects a MySQL database with a C++ backend and exposes the data using an HTTP API using the **Crow** C++ web framework.

---

## 📋 Prerequisites (One-time Setup)

Follow these steps **before building or running the project**:

### ✅ 1. Install MySQL Server (Windows)
- Download and install from: [https://dev.mysql.com/downloads/mysql](https://dev.mysql.com/downloads/mysql)
- During setup, remember:
  - Set the password for `root`
  - Enable TCP/IP networking (default port: 3306)

### ✅ 2. Install DBeaver (Optional: For GUI)
- Download: [https://dbeaver.io/download](https://dbeaver.io/download)
- Use it to:
  - Connect to MySQL
  - View and manage your databases

### ✅ 3. Create a Sample Database and Table

In MySQL (via DBeaver or CLI), run:

```sql
CREATE DATABASE pro1;

USE pro1;

CREATE TABLE user (
  id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(255),
  email VARCHAR(255)
);

INSERT INTO user (name, email) VALUES
('Alice', 'alice@example.com'),
('Bob', 'bob@example.com');

```


### 👤 Author

**M. Usama Mukhtar**  
🎓 Computer Science Student | Full Stack Developer  
🏢 Currently at: **Pismida**  
🎯 Passionate about building software that empowers people and creates opportunities for young Pakistanis to thrive in tech.

- 📧 **Email**: [f2024-0844@bnu.edu.pk](mailto:f2024-0844@bnu.edu.pk)  
- 🌐 **GitHub**: [github.com/usamamukhtar](https://github.com/usamamukhtar)  
- 📱 **Phone**: `03126336271`  
- 📍 **Location**: Lahore, Pakistan

> _“Empowering the next generation of developers through innovation and education.”_

