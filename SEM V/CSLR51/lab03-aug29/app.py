import mysql.connector

dbConnect = mysql.connector.connect(
    host= "127.0.0.1", 
    port = 3306,
    user = "root", 
    password = "KnineRX#11",
    db = "Blood"
)

dbCursor = dbConnect.cursor()

def createTable():
    createQuery = "CREATE TABLE blood_donor"
    dbCursor.execute(createQuery)

def insertDetails():
    donor_id = int(input("Enter your donor_id : "))
    aadhar_number = int(input("Enter your aadhar_number : "))
    name = input("Enter your name : ")
    blood_group = input("Enter your blood_group : ")
    region = input("Enter your region : ")
    phone_number = input("Enter your phone_number : ")

    insertQuery = "INSERT INTO blood_donor VALUES (%s, %s, %s, %s, %s, %s)"
    insertValues = (donor_id, aadhar_number, name, blood_group, region, phone_number)
    dbCursor.execute(insertQuery, insertValues)
    dbConnect.commit()

def displayDetails(blood_group):
    displayQuery = "SELECT * FROM blood_donor WHERE blood_group = %s"
    displayValue = (blood_group,)
    dbCursor.execute(displayQuery, displayValue)

    results = dbCursor.fetchall()

    for result in results:
        print(result)

def updateDetails(name):
    newPhoneNumber = input("Enter your new Phone Number : ")
    newRegion = input("Enter your new Region : ")

    updateQuery = "UPDATE blood_donor SET phone_number = %s, region = %s WHERE name = %s"
    updateValue = (newPhoneNumber, newRegion, name)
    dbCursor.execute(updateQuery, updateValue)
    dbConnect.commit()

def deleteDetails(name):
    deleteQuery = "DELETE FROM blood_donor WHERE name = %s"
    deleteValue = (name, )
    dbCursor.execute(deleteQuery, deleteValue)
    dbConnect.commit()

# insertDetails()
# displayDetails("O+ve")
# updateDetails("Nitish")
# deleteDetails("Nitish")
