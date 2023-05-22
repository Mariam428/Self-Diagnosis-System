# Self-Diagnosis-System

The project aims to develop a doctor-patient management system that allows users to log in using their username and password. The system differentiates between doctors and patients based on the provided credentials. 

If the username corresponds to a doctor, the system displays a list of functionalities including:

- Edit Info: Allows the doctor to modify their personal information.
- Add Disease: Enables the doctor to add a new disease to the system.
- Add Symptom to an Existing Disease: Allows the doctor to add symptoms to a disease they have previously added.
- Display All Diseases: Provides a comprehensive list of all diseases stored in the system.
- View Patients with a Certain Disease: Allows the doctor to view a list of patients who have been diagnosed with a specific disease.

If the username corresponds to a patient, the system displays a list of functionalities including:

- Find Out Your Disease Based on Your Symptoms: Helps the patient determine their potential disease based on the symptoms they provide.
- Display Symptoms for a Certain Disease: Allows the patient to view the symptoms associated with a particular disease.
- View Diagnosis History: Displays the patient's diagnosis history, providing a record of past diseases diagnosed.
- Clear Diagnosis History: Enables the patient to clear their diagnosis history.

The system maintains records for both patients and doctors. Patients are identified by their full name, account information, age, gender, and a disease history represented as an array of disease IDs. Doctors are identified by their full name, account information, and a list of diseases they have added represented as an array of disease IDs.

Diseases in the system are represented by their title, ID, general information, an array of symptoms, and the number of patients diagnosed with that disease.

The system also includes an account entity that stores the username and password for each user.

Some general notes about the system include:

- All doctors have access to view diseases added by different doctors.
- Doctors can only change or add symptoms to diseases they have previously added.
- To diagnose a patient with a disease, at least 60% of the symptoms must match the symptoms of that disease. If no exact match is found, the system will display "no exact match found" and provide a list of related diseases along with the matching percentage.
- If the symptoms provided by a patient do not match any diseases in the system, the system will display "no matches found".

When a patient is diagnosed with a disease, the system shows the general information associated with that disease, providing additional details and context.

Overall, this doctor-patient management system allows for efficient diagnosis and information retrieval, ensuring seamless communication and collaboration between doctors and patients.

## Project Technologies
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=cpp" />
  </a>
</p>

## Development Tools 
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=visualstudio"/>
  </a>
</p>
