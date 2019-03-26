#include "shared.h"
#include "neutral_interface.h"

// Handle facet event
inline int facet_event(const int global_nx, const int global_ny, const int nx,
                const int ny, const int x_off, const int y_off,
                const double inv_ntotal_particles, const double distance_to_facet,
                const double speed, const double cell_mfp, const int x_facet,
                Kokkos::View<const double *> density,
                const int* neighbours,
                const uint64_t pp,
                Kokkos::View<double *> p_energy,
                Kokkos::View<double *> p_weight,
                Kokkos::View<double *> p_mfp_to_collision,
                Kokkos::View<double *> p_dt_to_census,
                Kokkos::View<double *> p_x,
                Kokkos::View<double *> p_y,
                Kokkos::View<double *> p_omega_x,
                Kokkos::View<double *> p_omega_y,
                Kokkos::View<int *> p_cellx,
                Kokkos::View<int *> p_celly,
                double* energy_deposition,
                double* number_density,
                double* microscopic_cs_scatter, double* microscopic_cs_absorb,
                double* macroscopic_cs_scatter, double* macroscopic_cs_absorb,
                Kokkos::View<double *> energy_deposition_tally,
                int* cellx,
                int* celly,
                double* local_density);

// Handles a collision event
inline int collision_event(
    const int global_nx, const int nx, const int x_off, const int y_off,
    const uint64_t master_key, const double inv_ntotal_particles,
    const double distance_to_collision, const double local_density,
    Kokkos::View<const double *> cs_absorb_table_keys,
    Kokkos::View<const double *> cs_scatter_table_keys, 
    Kokkos::View<const double *> cs_absorb_table_values,
    Kokkos::View<const double *> cs_scatter_table_values, 
    const int cs_absorb_table_nentries,
    const int cs_scatter_table_nentries, 
    const uint64_t pp,
    Kokkos::View<double *> p_x,
    Kokkos::View<double *> p_y,
    int* p_cellx,
    int* p_celly,
    Kokkos::View<double *> p_weight,
    Kokkos::View<double *> p_energy,
    Kokkos::View<int *> p_dead,
    Kokkos::View<double *> p_omega_x,
    Kokkos::View<double *> p_omega_y,
    Kokkos::View<double *> p_dt_to_census,
    Kokkos::View<double *> p_mfp_to_collision,
    uint64_t* counter,
    double* energy_deposition,
    double* number_density,
    double* microscopic_cs_scatter,
    double* microscopic_cs_absorb,
    double* macroscopic_cs_scatter,
    double* macroscopic_cs_absorb,
    Kokkos::View<double *> energy_deposition_tally,
    int* scatter_cs_index,
    int* absorb_cs_index,
    double rn[NRANDOM_NUMBERS],
    double* speed);


inline void census_event(const int global_nx, const int nx, const int x_off,
                         const int y_off, const double inv_ntotal_particles,
                         const double distance_to_census, const double cell_mfp,
                         const uint64_t pp, 
                         Kokkos::View<double *> p_weight,
                         Kokkos::View<double *> p_energy,
                         Kokkos::View<double *> p_x,
                         Kokkos::View<double *> p_y,
                         Kokkos::View<double *> p_omega_x,
                         Kokkos::View<double *> p_omega_y,
                         Kokkos::View<double *> p_mfp_to_collision,
                         Kokkos::View<double *> p_dt_to_census,
                         Kokkos::View<int *> p_cellx,
                         Kokkos::View<int *> p_celly,
                         double* energy_deposition,
                         double* number_density,
                         double* microscopic_cs_scatter,
                         double* microscopic_cs_absorb,
                         Kokkos::View<double *> energy_deposition_tally);

// Tallies the energy deposition in the cell
inline void update_tallies(const int nx, const int x_off, const int y_off,
                                Particle* particle,
                                const double inv_ntotal_particles,
                                const double energy_deposition,
                                Kokkos::View<double *> energy_deposition_tally);

// // Handle the collision event, including absorption and scattering
// RAJA_DEVICE int handle_collision(Particle* particle,
//                                  const double macroscopic_cs_absorb,
//                                  uint64_t* counter,
//                                  const double macroscopic_cs_total,
//                                  const double distance_to_collision);

// // Sends a particle to a neighbour and replaces in the particle list
// void send_and_mark_particle(const int destination, Particle* particle);

// // Calculate the distance to the next facet
inline void calc_distance_to_facet(const int global_nx, const double x, const double y,
                            const int pad, const int x_off, const int y_off,
                            const double omega_x, const double omega_y,
                            const double speed, const int particle_cellx,
                            const int particle_celly, double* distance_to_facet,
                            int* x_facet,
                            Kokkos::View<const double *> edgex,
                            Kokkos::View<const double *> edgey);

// Calculate the energy deposition in the cell
inline double calculate_energy_deposition(
    const int global_nx, const int nx, const int x_off, const int y_off,
    Particle* particle, const double inv_ntotal_particles,
    const double path_length, const double number_density,
    const double microscopic_cs_absorb, const double microscopic_cs_total);

// Fetch the cross section for a particular energy value
inline double microscopic_cs_for_energy(Kokkos::View<const double *> keys, 
                                 Kokkos::View<const double *> values,
                                 const int nentries,
                                 const double p_energy,
                                 int* cs_index, double* cs);

inline void generate_random_numbers(const uint64_t pkey, const uint64_t master_key,
                             const uint64_t counter, double* rn0, double* rn1);

