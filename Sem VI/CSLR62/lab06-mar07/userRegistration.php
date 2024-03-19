<?php
session_start();
include_once 'dbconnect.php';

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
    if(mysqli_query($con, "INSERT INTO users(username, password, email) VALUES('" . $_POST['username'] . "', '" . $_POST['password'] . "', '" . $_POST['email'] . "')")) {
     header("location: index.html");
     exit();
    } else {
       echo "Error: " . $sql . "" . mysqli_error($con);
    }
}
?>