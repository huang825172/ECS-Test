# Install dependencies for configuring cmake project.

# add VulkanSDK repository
wget -qO - https://packages.lunarg.com/lunarg-signing-key-pub.asc | sudo apt-key add -
sudo wget -qO /etc/apt/sources.list.d/lunarg-vulkan-focal.list https://packages.lunarg.com/vulkan/lunarg-vulkan-focal.list
sudo apt update

# Install
sudo apt install -y \
    build-essential cmake \
    xorg-dev \
    vulkan-sdk