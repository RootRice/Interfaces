#include "GUI.h"
void quickSort(int array[], int low, int high);

Panel& GUI::Add_Panel(Panel::Panel_Properties& properties)
{
	Update_Panel_Order(+1);

	panels.push_back(Panel_Info{ Panel(properties, panels.size()), 0 });
	return panels[panels.size() - 1].p;
}

void GUI::Remove_Panel(Panel& panel, unsigned int index_guide)
{
	unsigned int starting_index = index_guide;
	const unsigned int last_element = panels.size() - 1;
	if (last_element < index_guide)
	{
		starting_index = last_element;
	}

	for (int i = starting_index; i > -1; i--)
	{
		if (&panel == &panels[i].p)
		{
			panels.erase(panels.begin() + i);
			break;
		}
	}

	Update_Panel_Order(-1);
}

void GUI::Draw_Panels()
{
	const int num_panels = panels.size();
	int* layers = new int[num_panels];
	for (int i = 0; i < num_panels; i++)
	{
		layers[i] = panels[i].layer;
	}

	quickSort(layers, 0, num_panels-1);

	for (int i = 0; i < num_panels; i++)
	{
		panels[i].p.Draw(window);
	}

	delete[] layers;
	int x = 0;
}

void GUI::Remove_Panel(unsigned int index)
{
	panels.erase(panels.begin() + index);
	Update_Panel_Order(-1);
}

void GUI::Update_Panel_Order(char update_amount)
{
	const int num_panels = panels.size();
	for (int i = 0; i < num_panels; i++)
	{
		panels[i].layer += update_amount;
	}
}

//https://www.programiz.com/dsa/quick-sort
void swap(int* a, int* b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int array[], int low, int high) 
{

	// select the rightmost element as pivot
	int pivot = array[high];

	// pointer for greater element
	int i = (low - 1);

	// traverse each element of the array
	// compare them with the pivot
	for (int j = low; j < high; j++) {
		if (array[j] <= pivot) {

			// if element smaller than pivot is found
			// swap it with the greater element pointed by i
			i++;

			// swap element at i with element at j
			swap(&array[i], &array[j]);
		}
	}

	// swap pivot with the greater element at i
	swap(&array[i + 1], &array[high]);

	// return the partition point
	return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
	if (low < high) {

		// find the pivot element such that
		// elements smaller than pivot are on left of pivot
		// elements greater than pivot are on righ of pivot
		int pi = partition(array, low, high);

		// recursive call on the left of pivot
		quickSort(array, low, pi - 1);

		// recursive call on the right of pivot
		quickSort(array, pi + 1, high);
	}
}