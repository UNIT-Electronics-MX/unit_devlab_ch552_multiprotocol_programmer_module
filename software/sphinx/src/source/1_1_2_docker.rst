Docker Configuration for Non-Privileged Users on Linux
=======================================================

This document details the procedure for configuring Docker so that containers, including the spkg container, may be built and executed without requiring superuser privileges.



1. Install Docker Engine
------------------------

There are two installation approaches. Select Option A for a simpler installation using the docker.io package, or Option B for the most current official release.



.. tabs:: 

  .. tab::  1.1 Option A – Using the docker.io Package

    Update the package index and install docker.io:

    .. code-block:: bash

      sudo apt update
      sudo apt install -y docker.io

  .. tab::  1.2 Option B – Installing the Latest Official Version

    The following steps remove any old installations and install the latest Docker components.

    .. code-block:: bash

      sudo apt remove docker docker-engine docker.io containerd runc

      sudo apt update
      sudo apt install -y \
        ca-certificates \
        curl \
        gnupg

      sudo install -m 0755 -d /etc/apt/keyrings

      curl -fsSL https://download.docker.com/linux/ubuntu/gpg | \
        sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg

      echo \
      "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] \
      https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | \
      sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

      sudo apt update
      sudo apt install -y docker-ce docker-ce-cli containerd.io docker-compose-plugin

2. Verify Docker Operation
---------------------------

Ensure the Docker daemon is active and verify the installation:

.. code-block:: bash

  sudo systemctl start docker
  sudo systemctl enable docker
  docker version

3. Configure User Access to Docker
------------------------------------

Add your user account to the docker group to allow Docker execution without root privileges:

.. code-block:: bash

  sudo usermod -aG docker $USER

After executing this command, re-authenticate by logging out and back in or by running:

.. code-block:: bash

  newgrp docker

4. Validate Non-Privileged Docker Usage
---------------------------------------

Confirm that Docker commands work without using sudo:

.. code-block:: bash

  docker ps

The command should return either an empty list or the column headers.

5. Verify Docker-Compose Plugin Installation
----------------------------------------------

Check the installation of docker-compose, whether using the legacy version or the modern plugin:

.. code-block:: bash

  docker-compose version     # For the classic (v1) version
  # or
  docker compose version     # For the modern (v2) plugin

If docker-compose is not available, install the required package:

.. code-block:: bash

  sudo apt install docker-compose

Or for the modern plugin:

.. code-block:: bash

  sudo apt install docker-compose-plugin

6. Running spkg Without sudo
-----------------------------

Once the configuration is complete, you may build images and compile projects with the spkg tool without requiring sudo privileges.

.. code-block:: bash

  ./spkg/spkg compose        # To build the Docker image
  ./spkg/spkg -p ./my_project bin    # To compile your project

Optional: Verify Docker Socket Permissions
--------------------------------------------

Ensure that the Docker socket is correctly configured with the proper group ownership and permissions:

.. code-block:: bash

  ls -l /var/run/docker.sock

The expected output should resemble:

.. code-block:: text

  srw-rw---- 1 root docker ...

If the permissions are not as specified, adjust them with:

.. code-block:: bash

  sudo chown root:docker /var/run/docker.sock
  sudo chmod 660 /var/run/docker.sock
