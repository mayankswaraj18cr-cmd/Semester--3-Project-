#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *previous;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    Node *cursor;
} Editor;

static void editor_init(Editor *editor) {
    editor->head = NULL;
    editor->tail = NULL;
    editor->cursor = NULL;
}

static int editor_insert(Editor *editor, char value) {
    Node *node = malloc(sizeof(*node));
    if (node == NULL) {
        return 0;
    }

    node->value = value;
    node->previous = editor->tail;
    node->next = NULL;

    if (editor->tail != NULL) {
        editor->tail->next = node;
    } else {
        editor->head = node;
    }

    editor->tail = node;
    editor->cursor = node;
    return 1;
}

static void editor_print(const Editor *editor) {
    const Node *current = editor->head;
    while (current != NULL) {
        putchar(current->value);
        current = current->next;
    }
    putchar('\n');
}

static void editor_destroy(Editor *editor) {
    Node *current = editor->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    editor_init(editor);
}

int main(void) {
    const char *sample = "HELLO";
    Editor editor;
    editor_init(&editor);

    for (const char *character = sample; *character != '\0'; ++character) {
        if (!editor_insert(&editor, *character)) {
            fprintf(stderr, "Unable to allocate a list node.\n");
            editor_destroy(&editor);
            return EXIT_FAILURE;
        }
    }

    printf("C implementation: ");
    editor_print(&editor);
    editor_destroy(&editor);
    return EXIT_SUCCESS;
}