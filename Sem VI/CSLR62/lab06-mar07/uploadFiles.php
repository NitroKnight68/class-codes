<?php
include_once 'dbconnect.php';

session_start();
if (!isset($_SESSION['loggedin'])) {
	header('Location: index.html');
	exit;
}

//check if form is submitted
if (isset($_POST['submit']))
{
    $filename = $_FILES['file1']['name'];

    //upload file
    if($filename != '')
    {
        $ext = pathinfo($filename, PATHINFO_EXTENSION);
        $allowed = ['pdf', 'txt', 'doc', 'docx', 'png', 'jpg', 'jpeg',  'gif'];
    
        //check if file type is valid
        if (in_array($ext, $allowed))
        {
            // get last record id
            $sql = 'SELECT max(id) as id from files';
            $result = mysqli_query($con, $sql);
            $row = mysqli_fetch_array($result);
            if (count($row) > 0)
                $filename = ($row['id']+1) . '-' . $filename;
            else
                $filename = '1' . '-' . $filename;

            //set target directory
            $path = 'uploads/';
                
            $created = @date('Y-m-d H:i:s');
            move_uploaded_file($_FILES['file1']['tmp_name'],($path . $filename));

            $user = "Public";
            if (isset($_POST['privacy']))
                $user = $_SESSION['name'];
            
            // insert file details into database
            $sql = "INSERT INTO files(fileName, createdAt, createdBy) VALUES('$filename', '$created', '$user')";
            mysqli_query($con, $sql);
            header("Location: privateFiles.php?st=success");
        }
        else
        {
            header("Location: privateFiles.php?st=error");
        }
    }
    else
        header("Location: privateFiles.php");
}
?>