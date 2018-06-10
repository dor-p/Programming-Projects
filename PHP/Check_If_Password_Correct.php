<?php 

// encrypting the password in a one way encryption (md5)
// using post variable 
// comparing the input password to the exsiting one in the passwords.txt file 


if(isset($_POST['user_password']))
{
	if(!empty($_POST['user_password']))
	{
		$user_password = md5($_POST['user_password']);
		
		$filename = 'passwords.txt';	
		$handle = fopen($filename, 'r');
		$file_password = fread($handle, filesize($filename));
		fclose($handle);
		
		if($user_password==$file_password)
		{
			echo 'CORRECT!!!.';
		}
		else
		{
			echo 'Incorrect try again...';
		}
	}
	else
	{
		echo 'Enter a password.';
	}
}
?>


<form action="index.php" method="POST">
	Password: <input type="text" name="user_password"><br/><br/>
	<input type="submit" value="Submit">
</form>