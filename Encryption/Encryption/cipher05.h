/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

#include <cassert>
#include <string>
#include "cipher.h"

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("Akins, T. (2008). Playfair Cypher.  \n Playfair cipher.Retrieved December 11, 2021, from \n http ://rumkin.com/tools/cipher/playfair.php.\nBhat, A. (2021, November 29).Playfair cipher with examples. \nGeeksforGeeks.Retrieved December 11, 2021, from \nhttps ://www.geeksforgeeks.org/playfair-cipher-with-examples/.\n");
    }

    /***********************************************************
     * GET PSEUDO AUTHOR
     * Returns the full name of the author of the pseudocode
     ***********************************************************/
    virtual std::string getPseudoAuth()
    {
        return std::string("Jaren Brown");
    }

    /***********************************************************
     * GET CIPHER NAME
     * Returns the name of the cipher used
     ***********************************************************/
    virtual std::string getCipherName()
    {
        return std::string("Playfair Cipher");
    }

    /**********************************************************
     * GET PSEUDOCODE
     * Returns the pseudocode as a string to be used by the caller.
     **********************************************************/
    virtual std::string getPseudocode()
    {
        std::string str;

        // TODO: please format your pseudocode

        // Helper Functions:
        // To Lowercase
        str = "toLowerCase(plain[], ps)\n";
        str += "FOR (I < ps)\n";
        str += "IF (64 < plain[i] < 91)\n";
        str += "plain[i] += 32\n";

        // Remove Spaces
        str += "removeSpaces(plain, ps\n";
        str += "i, count\n";
        str += "FOR (i < ps)\n";
        str += "IF (plain[i] NOT blank)\n";
        str += "plain[count++] = plain[i]\n";
        str += "plain[count] = '\0'\n";
        str += "RETURN count\n";

        // Generate Key Table
        str += "generateKeyTable(key[], ks, keyT[5][5]\n";
        str += "i, j, k, flag, dicty\n";
        str += "Dicty = calloc(26, sizeof(int))\n";
        str += "FOR (i < ks)\n";
        str += "IF (key[i] != j)\n";
        str += "Dicty[key[i] - 97] = 2\n";
        str += "Dicty[j - 97] = 1\n";
        str += "Reset i & j\n";
        str += "FOR (k < ks)\n";
        str += "IF (dicty[key[k] - 97] == 2)\n";
        str += "dicty[key[k] - 97] = 1\n";
        str += "keyT[i][j] = key[k]\n";
        str += "j++\n";
        str += "IF (j == 5)\n";
        str += "i++\n";
        str += "j = 0\n";
        str += "FOR (k < 26)\n";
        str += "IF (dicty[k] == 0)\n";
        str += "keyT[i][j] = (char)(k + 97)\n";
        str += "j++\n";
        str += "IF (j == 5)\n";
        str += "i++\n";
        str += "j = 0\n";

        // Search Function
        str += "search (keyT[5][5], a, b, arr[])\n";
        str += "i, j\n";
        str += "IF (a == ‘j’)\n";
        str += "a = ‘i’\n";
        str += "FOR (j < 5)\n";
        str += "IF (keyT[i][j] == a)\n";
        str += "arr[0] = i\n";
        str += "arr[1] = j\n";
        str += "ELSE IF (keyT[i][j] == b)\n";
        str += "arr[2] = i\n";
        str += "arr[3] = j\n";

        // Modulus 5 Function
        str += "mod5(a)\n";
        str += "RETURN (a % 5)\n";

        // Prepare Function
        str += "prepare(str[], ptrs)\n";
        str += "IF (ptrs % 2 != 0)\n";
        str += "str[ptrs++] = ‘z’\n";
        str += "str[ptrs] = ‘\0’\n";
        str += "RETURN ptrs\n";

        // The encrypt pseudocode
        // Encrypt Function
        str += "encrypt(str[], keyT[5][5], ps)\n";
        str += "i, a[4]\n";
        str += "FOR (i < ps)\n";
        str += "search(keyT, str[i], str[i+1],a)\n";
        str += "IF (a[0] == a[2])\n";
        str += "str[i] = keyT[a[0][mod5(a[1]+1)]\n";
        str += "str[i+1]=keyT[a[0]][mod5(a[3]+1)]\n";
        str += "ELSE IF (a[1] == a[3])\n";
        str += "str[i]=keyT[mod5(a[0]+1)][a[1]]\n";
        str += "str[i+1]=keyT[mod5(a[2]+1)][a[1]]\n";
        str += "ELSE\n";
        str += "str[i] = keyT[a[0]][a[3]]\n";
        str += "str[i+1]=keyT[a[2]][a[1]]\n";

        // Playfair Encrypt Function
        str += "encryptByPlayfairCipher(str[], key[])\n";
        str += "ps, ks, keyT[5][5]\n";
        str += "ks = strlen(key)\n";
        str += "ks = removeSpaces(key, ks)\n";
        str += "toLowerCase(key, ks)\n";
        str += "ps = strlen(str)\n";
        str += "toLowerCase(str, ps)\n";
        str += "ps = removeSpaces(str, ps)\n";
        str += "ps = prepare(str, ps)\n";
        str += "generateKeyTable(key, ks, keyT)\n";
        str += "encrypt(str, keyT, ps)\n";

        // The decrypt pseudocode
        //Decrypt Function
        str += "decrypt(str[], keyT[5][5], ps)\n";
        str += "i, a[4]\n";
        str += "FOR (i < ps)\n";
        str += "search(keyT, str[i], str[i + 1], a)\n";
        str += "IF (a[0] == a[2])\n";
        str += "str[i] = keyT[a[0]][mod5(a[1] - 1)]\n";
        str += "str[i + 1] = keyT[a[0]][mod5(a[3] - 1)]\n";
        str += "ELSE IF (a[1] == a[3])\n";
        str += "str[i] = keyT[mod5(a[0] - 1)][a[1]]\n";
        str += "str[i + 1] = keyT[mod5(a[2] - 1)][a[1]]\n";
        str += "ELSE\n";
        str += "str[i] = keyT[a[0]][a[3]]\n";
        str += "str[i + 1] = keyT[a[2]][a[1]]\n";

        //Playfair Decrypt Function
        str += "decryptByPlayfairCipher(char str[], char key[])\n";
        str += "char ps, ks, keyT[5][5]\n";
        str += "ks = strlen(key)\n";
        str += "ks = removeSpaces(key, ks)\n";
        str += "toLowerCase(key, ks)\n";
        str += "ps = strlen(str)\n";
        str += "toLowerCase(str, ps)\n";
        str += "ps = removeSpaces(str, ps)\n";
        str += "generateKeyTable(key, ks, keyT)\n";
        str += "decrypt(str, keyT, ps)\n";


        return str;
    }

    /**********************************************************
     * HELPER FUNCTIONS
     * These functions are used to help prepare the text and cipher
     * for encryption and decryption
     **********************************************************/
     /**********************************************************
      * TO LOWER CASE
      * Convert all characters to lower case
      **********************************************************/
    void toLowerCase(char plain[], int ps)
    {
        int i;
        for (i = 0; i < ps; i++) {
            if (plain[i] > 64 && plain[i] < 91)
                plain[i] += 32;
        }
    }

    /**********************************************************
     * REMOVE SPACES
     * Remove any spaces from the text
     **********************************************************/
    int removeSpaces(char* plain, int ps)
    {
        int i, count = 0;
        for (i = 0; i < ps; i++)
            if (plain[i] != ' ')
                plain[count++] = plain[i];
        plain[count] = '\0';
        return count;
    }

    /**********************************************************
     * GENERATE KEY TABLE
     * Generate the 5x5 key square
     **********************************************************/
    void generateKeyTable(char key[], int ks, char keyT[5][5])
    {
        int i, j, k, flag = 0, * dicty;

        // a 26 character hashmap
        // to store count of the alphabet
        dicty = (int*)calloc(26, sizeof(int));
        for (i = 0; i < ks; i++) {
            if (key[i] != 'j')
                dicty[key[i] - 97] = 2;
        }

        dicty['j' - 97] = 1;

        i = 0;
        j = 0;

        for (k = 0; k < ks; k++) {
            if (dicty[key[k] - 97] == 2) {
                dicty[key[k] - 97] -= 1;
                keyT[i][j] = key[k];
                j++;
                if (j == 5) {
                    i++;
                    j = 0;
                }
            }
        }

        for (k = 0; k < 26; k++) {
            if (dicty[k] == 0) {
                keyT[i][j] = (char)(k + 97);
                j++;
                if (j == 5) {
                    i++;
                    j = 0;
                }
            }
        }
    }

    /**********************************************************
     * SEARCH
     * Search for the characters of a digraph in the key square
     * and return their position
     **********************************************************/
    void search(char keyT[5][5], char a, char b, int arr[])
    {
        int i, j;

        if (a == 'j')
            a = 'i';
        else if (b == 'j')
            b = 'i';

        for (i = 0; i < 5; i++) {

            for (j = 0; j < 5; j++) {

                if (keyT[i][j] == a) {
                    arr[0] = i;
                    arr[1] = j;
                }
                else if (keyT[i][j] == b) {
                    arr[2] = i;
                    arr[3] = j;
                }
            }
        }
    }

    /**********************************************************
     * MODULUS 5
     * Find the modulus with 5
     **********************************************************/
    int mod5(int a)
    {
        return (a % 5);
    }

    /**********************************************************
     * PREPARE
     * Make the plain text length to be even
     **********************************************************/
    int prepare(char str[], int ptrs)
    {
        if (ptrs % 2 != 0) {
            str[ptrs++] = 'z';
            str[ptrs] = '\0';
        }
        return ptrs;
    }

    /**********************************************************
     * ENCRYPTION FUNCTIONS
     * An encrypt method and an encrypt by playfair cipher method
     **********************************************************/
     /**********************************************************
      * ENCRYPT TEXT
      * Perform the encryption
      **********************************************************/
    std::string encryptText(char str[], char keyT[5][5], int ps)
    {
        int i, a[4];

        for (i = 0; i < ps; i += 2) {

            search(keyT, str[i], str[i + 1], a);

            if (a[0] == a[2]) {
                str[i] = keyT[a[0]][mod5(a[1] + 1)];
                str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
            }
            else if (a[1] == a[3]) {
                str[i] = keyT[mod5(a[0] + 1)][a[1]];
                str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
            }
            else {
                str[i] = keyT[a[0]][a[3]];
                str[i + 1] = keyT[a[2]][a[1]];
            }
        }
        int size = sizeof(str) / sizeof(char);
        std::string cipherText = convertToString(str, size);
        return cipherText;
    }

    /**********************************************************
     * ENCRYPT BY PLAYFAIR CIPHER
     * Encrypt using the Playfair Cipher
     **********************************************************/
    std::string encryptByPlayfairCipher(char str[], char key[])
    {
        char ps, ks, keyT[5][5];

        // Key
        ks = strlen(key);
        ks = removeSpaces(key, ks);
        toLowerCase(key, ks);

        // Plaintext
        ps = strlen(str);
        toLowerCase(str, ps);
        ps = removeSpaces(str, ps);

        ps = prepare(str, ps);

        generateKeyTable(key, ks, keyT);

        std::string cipherText = encryptText(str, keyT, ps);
        return cipherText;
    }

    /**********************************************************
     * ENCRYPT
     * Prepare and encrypt text using the Playfair Cipher
     **********************************************************/
    virtual std::string encrypt(const std::string& plainText,
        const std::string& password)
    {
        std::string cipherText = plainText;
        char str[30], key[30];

        strcpy(key, password);
        strcpy(str, plainText);
        std::string cipherText = encryptByPlayfairCipher(str, key);
        return cipherText;
    }

    /**********************************************************
     * DECRYPTION METHODS
     * A decrypt method and a decrypt by playfair method
     **********************************************************/
     /**********************************************************
      * DECRYPT TEXT
      * Perform the decryption
      **********************************************************/
    std::string decryptText(char str[], char keyT[5][5], int ps)
    {
        int i, a[4];
        for (i = 0; i < ps; i += 2) {
            search(keyT, str[i], str[i + 1], a);
            if (a[0] == a[2]) {
                str[i] = keyT[a[0]][mod5(a[1] - 1)];
                str[i + 1] = keyT[a[0]][mod5(a[3] - 1)];
            }
            else if (a[1] == a[3]) {
                str[i] = keyT[mod5(a[0] - 1)][a[1]];
                str[i + 1] = keyT[mod5(a[2] - 1)][a[1]];
            }
            else {
                str[i] = keyT[a[0]][a[3]];
                str[i + 1] = keyT[a[2]][a[1]];
            }

        }
        int size = sizeof(str) / sizeof(char);
        std::string plainText = convertToString(str, size);
        return plainText;
    }

    /**********************************************************
     * DECRYPT BY PLAYFAIR CIPHER
     * Decrypt using the Playfair Cipher
     **********************************************************/
    std::string decryptByPlayfairCipher(char str[], char key[])
    {
        char ps, ks, keyT[5][5];

        // Key
        ks = strlen(key);
        ks = removeSpaces(key, ks);
        toLowerCase(key, ks);

        // ciphertext
        ps = strlen(str);
        toLowerCase(str, ps);
        ps = removeSpaces(str, ps);

        generateKeyTable(key, ks, keyT);

        std::string plainText = decrypt(str, keyT, ps);
        return plainText;
    }
    /**********************************************************
     * DECRYPT
     * Prepare and encrypt the text using the Playfair Cipher
     **********************************************************/
    virtual std::string decrypt(const std::string& cipherText,
        const std::string& password)
    {
        std::string plainText = cipherText;
        char str[30], key[30];

        // Key to be encrypted
        strcpy(key, "Monarchy");
        printf("Key text: %s\n", key);

        // Ciphertext to be decrypted
        strcpy(str, "gatlmzclrqtx");
        printf("Plain text: %s\n", str);

        // encrypt using Playfair Cipher
        decryptByPlayfairCipher(str, key);
        return plainText;
    }
};

#endif // CIPHER05_H