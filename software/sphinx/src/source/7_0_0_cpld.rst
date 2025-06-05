CPLD/FPGA
========================

This firmware is not an official programmer from Altera or Intel. Instead, it is a JTAG programmer for CPLD/FPGA devices based on the WCH CH552 USB microcontroller. It supports the Intel (formerly Altera) MAX II series and is compatible with Quartus Prime Lite.

.. warning::

    This firmware is a third-party implementation and **is not affiliated with or endorsed by Altera or Intel**. It is intended for educational, development, prototyping, and other lawful purposes only.

    Ensure that you comply with all applicable laws and regulations when using this firmware. **Use is at your own risk.** The user assumes all responsibility for any consequences, including potential legal implications. The author and distributor of this firmware **are not liable** for any damage, misuse, or legal issues arising from its use.

    **Proceed with caution and discretion.**

It is also compatible with:

- CPLD (MAX3000, MAX7000, MAX9000, and MAX II)
- FPGA (Stratix, StratixII, Cyclone, CycloneII, ACEX 1K, APEX20K, and FLEX 10K)
- Active configuration devices (EPCS1, EPCS4, EPCS16)

The ALTERA CPLD/FPGA programmer includes a USB cable and a 2.10 Core JTAG data line.

For programming Altera FPGA and CPLD devices, the Quartus software is used. A free version, Quartus Lite, is available. Quartus is the suite from Altera (now Intel) for programming, configuring, and using its products, and it fully supports the USB Blaster programmer and all its features.

Quick installation
------------------

.. note::
    To download the Intel Quartus Prime software, visit `Quartus Prime Installer <https://www.intel.com/content/www/us/en/software-kit/849770/intel-quartus-prime-lite-edition-design-software-version-24-1-for-windows.html>`_.

1. Open the file .exe 
    a. In the 24.1 version, add your devices
    b. Check the option "Agree to Intel License Agreement"
    c. Click on "Download and Install"
    d. Wait until the installation has completed succesfully  


.. raw:: html

        <div style="text-align: center;">
            <img src="./_static/cpld/intel_quartus_installer.png" alt="Intel Installer" style="width: 100%;">
            <p>Intel Quartus Prime Installer</p>
        </div>


Create a new project in Quartus
-------------------------------

Once installed the software and the driver for your CH552, we can create a new project. It's necessary that you've conected your device to your computer.

In the upper left, you will find the File > New Project Wizard tab.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/intel_quartus_installer.png" alt="New Project Wizard" style="width: 100%;">
                <p>New Prooject Wizard</p>
            </div>

a. Select the folder where you will save your project.
b. Choose an appropriate name to start the project.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/intel_quartus_installer.png" alt="New Project Wizard" style="width: 50%;">
                <p>New Prooject Wizard</p>
            </div>

c. In the project type, select the option empty project as shown below:

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/intel_quartus_installer.png" alt="Project Type" style="width: 50%;">
                <p>Project Type</p>
            </div>

d. Afterwards, click Next.
e. For this example, it is not necessary to add additional files.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/intel_quartus_installer.png" alt="Project Type" style="width: 50%;">
                <p>Project Type</p>
            </div>    

