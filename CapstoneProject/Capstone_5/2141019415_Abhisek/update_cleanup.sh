#!/bin/bash

echo "Updating system..."
sudo apt update && sudo apt upgrade -y

echo "Cleaning up unused packages..."
sudo apt autoremove -y
sudo apt autoclean

echo "System update and cleanup completed."

Explanation - 

sudo apt update: Updates the package lists for available updates.

sudo apt upgrade -y: Upgrades all installed packages to their latest versions automatically (-y accepts all prompts).

sudo apt autoremove -y: Removes unnecessary packages that were installed as dependencies but are no longer needed.

sudo apt autoclean: Clears out old package files that are no longer necessary.

