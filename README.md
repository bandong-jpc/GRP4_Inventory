# Release Notes

Inventory System Management refers to the process of tracking all or particular item in the inventory. It includes adding an item, updating an item, viewing the whole inventory list, search for an item, and deleting an item. This project includes software testing and coding.

# Features

## 1. Adding an Item

Feature that allows users to add items to the inventory list by inputting new Item ID, Description, Quantity, Expiration Date, and Price.

## 2. Updating an Item

Feature that allows users to update items in the inventory lists by searching for the ID then inputting the updated Description, Quantity, Expiration Date, and Price.

## 3. View the inventory list

Allows users to view the entire list of inventory items.

## 4. Searching an Item

Lets users look for a specific inventory item by searching for the ID.

## 5. Deleting an Item

Allows users to delete specific inventory items by inputting the item ID.

# Known Limitations/Defects

1. **Expiration date month's limit is not set** [GRP4_Bug Reports.xlsx, Bug #23]

Adding Expiration date> It cannot filter the month's specific number of dates. For it still accepts the date 31 for the month of February (2), April(4), June(6), September(9), November(11).

2. **Trailing empty lines read** [GRP4_Bug Reports.xlsx, Bug #19]

System will read into an empty line at the end of the inventory list if there is one and will copy values of the last line into it after update
