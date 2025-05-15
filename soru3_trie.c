#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26 // Ingilizce alfabe harf sayisi

// Her Trie d�g�m�n� tanimlayan yapi
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE]; // Her harf i�in bir �ocuk
    int isEndOfWord; // Bu d�g�m bir kelimenin sonu mu?
} TrieNode;

// Yeni bir Trie d�g�m� olusturur
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

// Trie'sine kelime ekler
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;

    while (*word) {
        int index = *word - 'a'; // Harfi index'e �evirir (�rnegin 'a' ? 0)

        if (current->children[index] == NULL)
            current->children[index] = createNode(); // �ocuk yoksa olustur

        current = current->children[index]; // Sonraki harfe ge�
        word++;
    }

    current->isEndOfWord = 1; // Kelime tamamlandi
}

// Trie i�inde kelimeyi arar
int search(TrieNode* root, const char* word) {
    TrieNode* current = root;

    while (*word) {
        int index = *word - 'a';

        if (current->children[index] == NULL)
            return 0; // Harf yoksa kelime yok demektir

        current = current->children[index];
        word++;
    }

    return current->isEndOfWord; // Son d�g�m kelime sonu mu?
}

// Ana fonksiyon � test �rnegi
int main() {
    TrieNode* root = createNode();

    insert(root, "cat");
    insert(root, "car");
    insert(root, "dog");

    // Arama �rnekleri
    printf("cat: %s\n", search(root, "cat") ? "Bulundu" : "Bulunamadi");
    printf("can: %s\n", search(root, "can") ? "Bulundu" : "Bulunamadi");
    printf("dog: %s\n", search(root, "dog") ? "Bulundu" : "Bulunamadi");

    return 0;
}

