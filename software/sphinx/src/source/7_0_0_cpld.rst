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
                <img src="./_static/cpld/new_project.png" alt="New Project Wizard" style="width: 80%;">
                <p>New Project Wizard</p>
            </div>

a. You will see the New Project Wizard window

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/cpld/introduction_new_p.png" alt="Introduction to New Project Wizard" style="width: 100%;">
                <p>Introduction to the New Project Wizard</p>
            </div>

a. Select the option "Next".
b. Choose an appropriate name to start the project.
c. Select the folder where you will save your project.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/cpld/project_type.png" alt="Project Type" style="width: 100%;">
                <p>Project Type</p>
            </div>

d. In the project type, select the option empty project as shown above:
e. Afterwards, click Next.
f. For this example, it is not necessary to add additional files.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/cpld/add_files.png" alt="Add files" style="width: 100%;">
                <p>How to add files (optional)</p>
            </div>    

g. Afterwards, click Next.
h. This is the where you can select your device, package, pin count, core speed grade.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/cpld/devices.png" alt="Family, device and board settings" style="width: 100%;">
                <p>Family, device and board settings</p>
            </div> 

i. EDA Tools Settings.

.. note::
    These options do not define the device family (e.g., MAX II, Cyclone IV, etc.); 
    rather, they specify how Quartus will connect to third-party tools (ModelSim, Synopsys, etc.). 
    If you do not have any external EDA tools, you may leave all options set to <None>, and Quartus 
    will use its internal functionality to compile and generate programming files.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/cpld/eda_settings.png" alt="EDA Tools Settings" style="width: 100%;">
                <p>EDA Tools Settings </p>
            </div> 

j. In this window, you will be able to see a summary of your settings.

.. raw:: html

            <div style="text-align: center;">
                <img src="./_static/cpld/summary.png" alt="Summary" style="width: 100%;">
                <p>Summary</p>
            </div> 

k. Afterwards, click Finish.
