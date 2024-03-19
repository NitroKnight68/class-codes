<?php
session_start();

$success_count = 0;
$fail_count = 0;

$DATABASE_HOST = 'localhost';
$DATABASE_USER = 'root';
$DATABASE_PASS = '';
$DATABASE_NAME = 'lab05-feb22';

$con = mysqli_connect($DATABASE_HOST, $DATABASE_USER, $DATABASE_PASS, $DATABASE_NAME);

if ( mysqli_connect_errno() ) {
	exit('Failed to connect to MySQL: ' . mysqli_connect_error());
}

if ( !isset($_POST['username'], $_POST['password']) ) {
	exit('Please fill both the username and password fields!');
}

if (!preg_match("/^[a-zA-Z ]+$/",$_POST['username'])) {
    exit('Name must contain only alphabets and space');
}

if(!filter_var($_POST['email'],FILTER_VALIDATE_EMAIL)) {
    exit('Please Enter Valid Email ID');
}

if(strlen($_POST['password']) < 6) {
    exit('Password must be minimum of 6 characters');
}

if (!$error) {
    if(mysqli_query($con, "INSERT INTO accounts(username, password, email) VALUES('" . $_POST['username'] . "', '" . $_POST['password'] . "', '" . $_POST['email'] . "')")) {
     header("location: index.html");
     exit();
    } else {
       echo "Error: " . $sql . "" . mysqli_error($con);
    }
}
?>