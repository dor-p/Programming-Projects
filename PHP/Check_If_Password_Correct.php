<?php 

// This script is hashing the input password in a one way hash function (md5) and comparing it to the already hashed password
// that is in 'password.txt'
// furthermore, I will be using post variable & method .



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
