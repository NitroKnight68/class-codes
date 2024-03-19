<?php
include_once 'dbconnect.php';

// fetch files
$privacy = "Public";
$sql = "SELECT * FROM `files` WHERE `createdBy` = '".$privacy."' ORDER BY `id` DESC";
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
</body>
</html>