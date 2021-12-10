/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H
#include <iostream>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
    Cipher03()
    {
        valueMinimum = ' ';
        valueMaximum = '~';
        sizeAlphabet = valueMaximum - valueMinimum + 1;
    }
    virtual std::string getPseudoAuth() { return "Michael Jackson"; }
    virtual std::string getCipherName() { return "Affine Cipher"; }
    virtual std::string getEncryptAuth() { return "Michael Jackson"; }
    virtual std::string getDecryptAuth() { return "Michael Jackson"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        std::string s;
        s += "dcode.fr (2021), ";
        s += "\"Affine Cipher - Online Decryption, Encoder, Decoder, Calculator\", \n Retrieved: ";
        s += "https://www.dcode.fr/affine-cipher";
        return s;
    }

    /**********************************************************
     * GET PSEUDOCODE
     * Returns the pseudocode as a string to be used by the caller.
     **********************************************************/
    virtual std::string getPseudocode()
    {
        std::string str;

        // TODO: please format your pseudocode
        // The encrypt pseudocode
        str = "encrypt(plaintext, password)\n";
        str += "   a <- indexFromCharacter(password[0]) % sizeAlphabet\n";
        str += "   b <- indexFromCharacter(password[1]) % sizeAlphabet\n";
        str += "   a <- indexFromCharacter(password[0]) % sizeAlphabet\n";
        str += "   FOR p is all values of plainText\n";
        str += "      y <- (a * indexFromCharacter(*p) + b) % size\n";
        str += "      cipherText += characterFromIndex(y)\n";
        str += "   RETURN cipherText\n\n";

        // The decrypt pseudocode
        str += "decrypt(cipherText, password)\n";
        str += "   a <- indexFromCharacter(password[0]) % sizeAlphabet\n";
        str += "   b <- indexFromCharacter(password[1]) % sizeAlphabet\n";
        str += "   FOR p is all values of cipherText\n";
        str += "      x <- (modInverse(a) * (indexFromCharacter(*p) - b)) % size\n";
        str += "      plainText += characterFromIndex(x)\n";
        str += "   RETURN plainText\n\n";

        return str;
    }

    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string encrypt(const std::string& plainText,
        const std::string& password)
    {
        std::string cipherText;
        // TODO - Add your code here
        int a = indexFromCharacter(password[0]) % sizeAlphabet;
        int b = indexFromCharacter(password[1]) % sizeAlphabet;

        for (const char* p = plainText.c_str(); *p; p++)
        {
            // affine equation y = (ax+b) % sizeAlphabet
            int x = indexFromCharacter(*p);
            int y = (a * x + b) % sizeAlphabet;
            cipherText += characterFromIndex(y);
        }
        return cipherText;
    }

    /**********************************************************
     * DECRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string decrypt(const std::string& cipherText,
        const std::string& password)
    {
        std::string plainText;
        // TODO - Add your code here
        int a = indexFromCharacter(password[0]) % sizeAlphabet;
        int b = indexFromCharacter(password[1]) % sizeAlphabet;

        for (const char* p = cipherText.c_str(); *p; p++)
        {
            // affine equation x = a'(y - b) % sizeAlphabet
            int y = indexFromCharacter(*p);
            int A = calcModularInverse(a);
            int x = ((y - b) * A) % sizeAlphabet;
            if (x < 0)
                x += sizeAlphabet;
            plainText += characterFromIndex(x);
        }
        return plainText;
    }
private:
    /**************************************************
    * INDEX FROM CHARACTER
    * Get an index value from a given letter.
    * Author: Bro. Helfrich
    *************************************************/
    int indexFromCharacter(char letter)
    {
        // return the value
        if (letter > valueMaximum || letter < valueMinimum)
            return 0;
        else
            return (int)(letter - valueMinimum);
    }

    /**************************************************
     * CHARACTER FROM INDEX
     * Get the characer value from a given index.
     * Author: Bro. Helfrich
     *************************************************/
    char characterFromIndex(int index)
    {
        if (index >= 0 && index < sizeAlphabet)
            return (char)(index + valueMinimum);
        else
            return ' ';
    }

    // Get the Modular inverse of a value such that (a * A') % sizeAlphabet == 1
    int calcModularInverse(int a)
    {
        for (int x = 0; x <= sizeAlphabet; x++)
            if ((a * x) % sizeAlphabet == 1)
                return x;
    }

    char valueMinimum;
    char valueMaximum;
    int sizeAlphabet;
};

#endif // CIPHER03_H