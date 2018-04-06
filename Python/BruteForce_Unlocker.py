import zipfile
import itertools
import string

class BreakZip:

    def __init__(self, file_name, outdir):
        self.file_name = file_name
        self.outdir = outdir

    def guess_password(self):
        """Using a loop to Brute Force the zip file with combos of Number & Characters"""

        zip_arc = zipfile.ZipFile(self.file_name)
        chars = string.ascii_lowercase + string.digits
        attempts = 0
        for password_length in range(1, 9):
            for guess in itertools.product(chars, repeat=password_length):
                attempts += 1
                guess = ''.join(guess)
                bguess = guess.encode()
                try:
                    zip_arc.extractall(self.outdir, pwd=bguess)
                    print('Cracked the Pass, it is ', guess, 'attemp number is - ', attempts)
                    break
                except:
                    print("Trying.... attemp number is - " ,attempts)
                    pass

