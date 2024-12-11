#include <stdio.h>
#include <stdlib.h>

struct node {
    float coef;
    int expo;
    struct node *link;
};

struct node *create(struct node *);
struct node *insert_s(struct node *, float, int);
struct node *insert(struct node *, float, int);
void display(struct node *ptr);
void poly_add(struct node *, struct node *);
void poly_mult(struct node *, struct node *);

int main() {
    struct node *start1 = NULL, *start2 = NULL;

    printf("Enter polynomial 1:\n");
    start1 = create(start1);

    printf("Enter polynomial 2:\n");
    start2 = create(start2);

    printf("Polynomial 1 is: ");
    display(start1);

    printf("Polynomial 2 is: ");
    display(start2);

    poly_add(start1, start2);
    poly_mult(start1, start2);

    return 0;
}

// Function to create the polynomial
struct node *create(struct node *start) {
    int i, n, ex;
    float co;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter coefficient for term %d: ", i);
        scanf("%f", &co);

        printf("Enter exponent for term %d: ", i);
        scanf("%d", &ex);

        start = insert_s(start, co, ex);
    }

    return start;
}

// Function to insert a term in sorted order (by exponent)
struct node *insert_s(struct node *start, float co, int ex) {
    struct node *ptr, *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = co;
    tmp->expo = ex;

    // Insert at the beginning or if the exponent is greater than the first one
    if (start == NULL || ex > start->expo) {
        tmp->link = start;
        start = tmp;
    } else {
        ptr = start;

        // Traverse the list to find the correct position
        while (ptr->link != NULL && ptr->link->expo >= ex) {
            ptr = ptr->link;
        }

        tmp->link = ptr->link;
        ptr->link = tmp;
    }

    return start;
}

// Function to insert a term at the end of the list
struct node *insert(struct node *start, float co, int ex) {
    struct node *ptr, *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = co;
    tmp->expo = ex;

    // If list is empty, insert at the beginning
    if (start == NULL) {
        tmp->link = start;
        start = tmp;
    } else {
        ptr = start;

        // Traverse the list to insert at the end
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }

        tmp->link = ptr->link;
        ptr->link = tmp;
    }

    return start;
}

// Function to display the polynomial
void display(struct node *ptr) {
    if (ptr == NULL) {
        printf("Zero polynomial\n");
        return;
    }

    while (ptr != NULL) {
        printf("(%.1fx^%d)", ptr->coef, ptr->expo);
        ptr = ptr->link;

        if (ptr != NULL)
            printf(" + ");
        else
            printf("\n");
    }
}

// Function to add two polynomials
void poly_add(struct node *p1, struct node *p2) {
    struct node *start3 = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            start3 = insert(start3, p1->coef, p1->expo);
            p1 = p1->link;
        } else if (p2->expo > p1->expo) {
            start3 = insert(start3, p2->coef, p2->expo);
            p2 = p2->link;
        } else if (p1->expo == p2->expo) {
            start3 = insert(start3, p1->coef + p2->coef, p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    // Add remaining terms from either polynomial
    while (p1 != NULL) {
        start3 = insert(start3, p1->coef, p1->expo);
        p1 = p1->link;
    }

    while (p2 != NULL) {
        start3 = insert(start3, p2->coef, p2->expo);
        p2 = p2->link;
    }

    printf("\nAdded polynomial is: ");
    display(start3);
}

// Function to multiply two polynomials
void poly_mult(struct node *p1, struct node *p2) {
    struct node *start3 = NULL;
    struct node *p2_beg = p2;

    if (p1 == NULL || p2 == NULL) {
        printf("Multiplied polynomial is zero polynomial\n");
        return;
    }

    while (p1 != NULL) {
        p2 = p2_beg;

        while (p2 != NULL) {
            start3 = insert_s(start3, p1->coef * p2->coef, p1->expo + p2->expo);
            p2 = p2->link;
        }

        p1 = p1->link;
    }

    printf("\nMultiplied polynomial is: ");
    display(start3);
}

