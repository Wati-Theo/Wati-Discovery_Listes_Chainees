#include "lib.h"

Liste	*initialisation(void)
{
	Liste	*liste = malloc(sizeof(*liste));
	Element	*element = malloc(sizeof(*element));

	if (!liste || !element)
		return (NULL);
	element->nombre = 0;
	element->suivant = NULL;
	liste->premier = element;

	return (liste);
}

void	insertion(Liste *liste, int nvNombre)
{
	Element	*nvElement = malloc(sizeof(*nvElement));

	nvElement->nombre = nvNombre;
	nvElement->suivant = liste->premier;
	liste->premier = nvElement;
}

void	suppression(Liste *liste)
{
	if (liste->premier)
	{
		Element *aSuppr = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSuppr);
	}
}

void	afficherListe(Liste *liste)
{
	Element *elementActu = liste->premier;
	while (elementActu != NULL)
	{
		printf("%d -> ", elementActu->nombre);
		elementActu = elementActu->suivant;
	}
	printf("NULL\n");
}

int	main(void)
{
	Liste	*ma_Wati_Liste;

	ma_Wati_Liste = initialisation();

	insertion(ma_Wati_Liste, 3);	
	insertion(ma_Wati_Liste, 2);
	insertion(ma_Wati_Liste, 1);

	suppression(ma_Wati_Liste);

	afficherListe(ma_Wati_Liste);
	return (0);
}
