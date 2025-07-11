# Library Management System in C++
# Webhook Test - May 22, 2025

## Overview
A modular, console-based **Library Management System (LMS)** built in C++ to manage books, members, loans, fines, and reporting. Designed with maintainability, scalability, and data persistence in mind.

## Features

### Book Management
- Add, edit, delete, and search books
- Track book availability and status (borrowed/lost)
- Organize by genre and list all books

### Member Management
- Add, edit, delete, and search members
- Load/save member data to/from files
- Track subscription status

### Loans & Reservations
- Issue, return, and renew loans
- Reserve unavailable books
- Load/save loan records
- Check overdue loans

### Fines & Payments
- Add, search, delete fines
- Process full/partial payments
- Fine exemption logic
- Persistent storage for fine records

### Reports & Analytics
- Generate reports: popular books, active members, inventory, etc.
- Monthly summaries and statistics dashboard
- Export reports to `.txt` / `.csv`

### Admin & Security
- Login system with password hashing
- Role-based access (admin/librarian)
- Action logs and full backup/restore support

## Technical Highlights
- Modular C++ codebase (header and source files per module)
- File I/O (binary & text) for persistent data
- `struct`, `enum`, function overloading, and inline functions
- Robust error handling and input validation

## Setup
1. Clone the repository  
2. Compile all `.cpp` files using any C++11+ compiler  
3. Run the executable from terminal

## Integration
- GitHub repository with version control  
- Telegram bot integration for team updates  
