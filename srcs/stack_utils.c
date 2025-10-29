//stack oluşturucaz 
//Node ekleyeceğiz 
//Tekrar eden sayı var mı yok mu 
//Belleği düzgünce boşaltmak olucaz 



/*
bu fonksiyonda ki amacım;
1- yeni bir t_node oluşturmak,
2- Eğer liste boşsa başa eklemek
3- Eğer doluysa sonuna eklemek
*/
void link_new_nod(t_node **stack, int value)
{
    t_node *new;
    t_node *last;

    new = malloc(sizeof(t_node));
    if(new == NULL)
        return (NULL);
    
    new -> value = value; 
    new -> index = -1;
    new -> keep = 0;
    new -> step = ;
    new ->next = NULL;

    if(!*stack) // eğer stack boşsa bu yeni düğüm head olur. 
    { 
        *stack = new; 
        return; 
    }

    last = *stack;  
    while(last -> next)
        last = last->next; // değişkenin en sonuna gidiliyor.
    last->next = new;  // son elemana ulaşıldığında, last ->next = new ile yeni düğüm bağlanmış oluyor. 
    
}

// Listeye aynı sayının iki kez  girilip girilmedeğini kontrol eder.
/*
Dış döngü(outer) -> stack'in her elemanı sırayla seçer. 
İç döngü(inner) -> her seferinde outerdan geri kalan elemanları bakar.
Eğer iç ve dış döngü value'ları eşitse o zaman hata fırlat. 
*/ 
void find_repeats(t_node *stack)
{
    t_node *outer; //listede ki her elemanı teker teker temsil eder. 
    t_node *inner; //her outer elemanın kalan elemanlarını temsil eder. 

    
    
    outer = stack;
    while(outer)
    {
        while(inner)
        {
            if(outer->value == inner->value)
            {
                PANIC(&stack, NULL, "Duplicate NUmber");
            }
            inner = inner->next;
        }
        
        outer = outer->next;
    }
}

void purge_stack(t_node **stack)
{
    t_node *temp;

    while(*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}