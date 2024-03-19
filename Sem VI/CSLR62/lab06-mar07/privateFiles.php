<?php
include_once 'dbconnect.php';

session_start();
if (!isset($_SESSION['loggedin'])) {
	header('Location: index.html');
	exit;
}

// fetch files
$sql = "SELECT * FROM `files` WHERE `createdBy` = '".$_SESSION['name']."' ORDER BY `id` DESC";
$result = mysqli_query($con, $sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Upload View & Download file in PHP and MySQL | Demo</title>
    <meta content="width=device-width, initial-scale=1.0" name="viewport" >
    <link href="styles.css" rel="stylesheet" type="text/css">
</head>
<body>
<br/>
<div class="container">
    <div class="row">
        <div class="col-xs-8 col-xs-offset-2 well">
        <form action="uploadFiles.php" method="post" enctype="multipart/form-data">
            <legend>Select File to Upload:</legend>
            <div class="form-group">
                <input type="file" name="file1" />
            </div>
            <br>
            <div class="form-group">
                <input type="checkbox" name="privacy" value="Private" />
                <label for="privacy">Private File</label>
            </div>
            <br>
            <div class="form-group">
                <input type="submit" name="submit" value="Upload" class="btn btn-info"/>
            </div>
            <?php if(isset($_GET['st'])) { ?>
                <div class="alert alert-danger text-center">
                <?php if ($_GET['st'] == 'success') {
                        echo "File Uploaded Successfully!";
                    }
                    else
                    {
                        echo 'Invalid File Extension!';
                    } ?>
                </div>
            <?php } ?>
        </form>
        </div>
    </div>
    <br>
    <div class="row">
        <div class="col-xs-8 col-xs-offset-2">
            <table class="table table-striped table-hover">
                <thead>
                    <tr>
                        <th>#</th>
                        <th>File Name</th>
                        <th>View</th>
                        <th>Download</th>
                    </tr>
                </thead>
                <tbody>
                <?php
                $i = 1;
                while($row = mysqli_fetch_array($result)) { ?>
                <tr>
                    <td><?php echo $i++; ?></td>
                    <td><?php echo $row['fileName']; ?></td>
                    <td><a href="uploads/<?php echo $row['fileName']; ?>" target="_blank">View</a></td>
                    <td><a href="uploads/<?php echo $row['fileName']; ?>" download>Download</td>
                </tr>
                <?php } ?>
                </tbody>
            </table>
        </div>
    </div>
</div>
<br>
<a href="publicFiles.php" class="switch check">Public</a><br>
<a href="userLogout.php"><i class="fas fa-sign-out-alt"></i>Logout</a>
</body>
</html>