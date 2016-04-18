#include <openssl/evp.h>
#include <openssl/sha.h>
// crypto.h used for the version
#include <openssl/crypto.h>


void PBKDF2_HMAC_SHA_384_string(const char* pass, const unsigned char* salt, int32_t iterations, uint32_t outputBytes, char* hexResult)
{
    unsigned int i;
    unsigned char digest[outputBytes];
    PKCS5_PBKDF2_HMAC(pass, strlen(pass), salt, strlen(salt), iterations, EVP_sha384(), outputBytes, digest);
    for (i = 0; i < sizeof(digest); i++)
        sprintf(hexResult + (i * 2), "%02x", 255 & digest[i]);
}

void PBKDF2_HMAC_SHA_512_string(const char* pass, const unsigned char* salt, int32_t iterations, uint32_t outputBytes, char* hexResult)
{
    unsigned int i;
    unsigned char digest[outputBytes];
    PKCS5_PBKDF2_HMAC(pass, strlen(pass), salt, strlen(salt), iterations, EVP_sha512(), outputBytes, digest);
    for (i = 0; i < sizeof(digest); i++)
        sprintf(hexResult + (i * 2), "%02x", 255 & digest[i]);
}

int main(){
    // 2*outputBytes+1 is 2 hex bytes per binary byte,
    // and one character at the end for the string-terminating \0
    char hexResult[2*outputBytes+1];
    memset(hexResult,0,sizeof(hexResult));
    char pass[7] = "secret";
    char salt[8] = "salt";
    int iterations = 10000;
    int outputBytes = 512;
    PBKDF2_HMAC_SHA_512_string(pass, salt, iterations, outputBytes, hexResult);
    printf("%s\n", hexResult);
}