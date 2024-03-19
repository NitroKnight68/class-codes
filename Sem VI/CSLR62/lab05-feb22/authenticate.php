<?php
session_start();

$DATABASE_HOST = 'localhost';
$DATABASE_USER = 'root';
$DATABASE_PASS = '';
$DATABASE_NAME = 'lab05-feb22';

$con = mysqli_connect($DATABASE_HOST, $DATABASE_USER, $DATABASE_PASS, $DATABASE_NAME);

if ( mysqli_connect_errno() ) {
	exit('Failed to connect to MySQL: ' . mysqli_connect_error());
}

if ($stmt = $con->prepare('SELECT id, password FROM accounts WHERE username = ?')) {
	$stmt->bind_param('s', $_POST['username']);
	$stmt->execute();
	$stmt->store_result();

    if ($stmt->num_rows > 0) {
        $stmt->bind_result($id, $password);
        $stmt->fetch();
        if ($_POST['password'] === $password) {
            session_regenerate_id();
            $_SESSION['loggedin'] = TRUE;
            $_SESSION['name'] = $_POST['username'];
            $_SESSION['id'] = $id;
            $_SESSION["success_count"] += 1;
            //header('Location: home.php');
        } else {
            $_SESSION["fail_count"] += 1;
            //exit('Incorrect username or password');
        }
    } else {
        $_SESSION["fail_count"] += 1;
        //exit('Incorrect username or password');
    }
    echo('Number of successful attempts is ' . $_SESSION["success_count"] . '<br>Number of failed attempts is ' . $_SESSION["fail_count"]);
	$stmt->close();
}
?>